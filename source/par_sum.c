/*
Progração Concorrente - 3a
Gabriel Thiago H. Dos Santos
RA: 107774

Programando em Paralelo: Pthreads
   Leitura e distribuições de processamentos para tarefas
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>

// diretiva - macros
#define EMPTY_Q(q) ((q)->first == NULL)
#define CREATE_QUEUE(q) ({(q)->first = NULL ; (q)->end_q = NULL;})
#define ADD_V(var, quantity, block) ({ \
      pthread_mutex_lock(&block);      \
      var += quantity;                 \
      pthread_mutex_unlock(&block);    \
      })
#define SWAP_V(var, new, block) ({     \
      pthread_mutex_lock(&block);      \
      var = new;                       \
      pthread_mutex_unlock(&block);    \
      })


typedef struct no {
   char action;
   long num;
   struct no *next;
} task_type;

typedef struct {
   task_type *first;
   task_type *end_q;
} queue;


long sum = 0, odd = 0, min = LONG_MAX, max = LONG_MIN;
bool done = false;
pthread_mutex_t sum_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t odd_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t min_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t max_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t q_mutex    = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t q_condvar   = PTHREAD_COND_INITIALIZER;

// volatil?
queue q;

task_type *remove_q(queue *q);
bool insert_q(queue *q, char action, long num);

void *worker(void *arg) {
   //long tid = (long)arg; // SEM USO
   task_type *task;

   while (!EMPTY_Q(&q) || !done) {                  // enquanto houver serviços OU não ter finalizado
      pthread_mutex_lock(&q_mutex);

      while ( EMPTY_Q(&q) && !done ) {              // enquanto não houver serviços E não ter finalizado
         pthread_cond_wait(&q_condvar, &q_mutex);
      }

      task = remove_q(&q);
      pthread_mutex_unlock(&q_mutex);

      if (task){                                    // se removido
         int sleep_i = task->num;
         sleep(sleep_i);

         ADD_V(sum, task->num, sum_mutex);

         if (task->num % 2 == 1) {
            ADD_V(odd, 1, odd_mutex);
         }
         if (task->num < min) {
            SWAP_V(min, task->num, min_mutex);
         }
         if (task->num > max) {
            SWAP_V(max, task->num, max_mutex);
         }
         free(task);
      }
   }
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   int num_threads = -1, opt, i;
   char *name_file = NULL, action;
   void *status = NULL;
   long num;

   while ((opt = getopt(argc, argv, "t:f:")) != -1) {
      switch (opt) {
         case 't':
            num_threads = strtoul(optarg, NULL, 0);
            break;

         case 'f':
            name_file   = optarg;
            break;

         default:
            fprintf(stderr,
                    "Usage: %s [-t <quantidade de thread>] [-f <nome do "
                    "arquivo>]\n",
                    argv[0]);
            exit(EXIT_FAILURE);  
      }
   }

   if (num_threads <= 0){
      printf("Quantidade inválida de de Threads!\n");
      exit(EXIT_FAILURE);
   }

   FILE *fin = fopen(name_file, "r");
   if (!fin) {
      printf("\nErro ao abrir arquivo!\nVerifique o caminho/nome do arquivo\n\n");
      exit(EXIT_FAILURE);
   }

   pthread_t threads[num_threads];
   pthread_attr_t attr;

   CREATE_QUEUE(&q);

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for (i = 0; i < num_threads; i++)
      pthread_create(&threads[i], &attr, worker, (void *)(intptr_t)i);

   pthread_attr_destroy(&attr);


   while (fscanf(fin, "%c %ld\n", &action, &num) == 2) {
      if (action == 'p') {
         pthread_mutex_lock(&q_mutex);
         // insere e acorda thread
         insert_q(&q, action, num);
         pthread_cond_broadcast(&q_condvar);
         pthread_mutex_unlock(&q_mutex);
      } else if (action == 'e') {
         int sleep_i = num;
         sleep(sleep_i);
      } else {
         printf("ERROR: Unrecognized action: '%c'\n", action);
         exit(EXIT_FAILURE);
      }
   }
   fclose(fin);
   done = true;
   
   pthread_cond_broadcast(&q_condvar);    
   for (i = 0; i < num_threads; i++){
      pthread_join(threads[i], &status);
      free(status);
   }

   printf("%ld %ld %ld %ld\n", sum, odd, min, max);

   pthread_mutex_destroy(&q_mutex);  
   pthread_cond_destroy(&q_condvar); 
   return EXIT_SUCCESS;
}

bool insert_q(queue *q, char action, long num) {
   task_type *p;
   p = malloc(sizeof(task_type));

   if (p == NULL) return false;

   p->action = action;
   p->num    = num;
   p->next   = NULL;

   if (q->first == NULL)
      q->first = p;
   else
      q->end_q->next = p;

   q->end_q = p;
   return true; 
}

task_type *remove_q(queue *q) {
   task_type *p;
   if (EMPTY_Q(q)) {
      return NULL;
   }

   p = q->first;

   q->first = p->next;
   if (q->first == NULL) q->end_q = NULL;

   return p;
}
