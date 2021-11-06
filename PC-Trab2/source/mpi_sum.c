/* Trab 2 - Prog. Concorrente
 *
 * Comp.: mpicc program.c
 * Exec.: mpirun -n 10 --oversubscribe a.out
 *
 *                                            Representação
 *  ---------------------------------------------------------------------------------------------------
 * |                                                                                                   \
 * |               Worker                                        Master                                |
 * |                 ↓                                             ↓                                   |
 * |                 ↓              tag 1 && id                    ↓                                   |
 * |    →→→→→→→→→> ocioso   →→→→→→→→→→→→→→→→→→→→→→→→→→→→>        recebe   <←←←←←←←←←←←←←←←←←←          |
 * |  ↗                                                         ↙     ↘                       ↖        |
 * | ↑                                                        ↙         ↘                      ↑ loop  |
 * | ↑                                  tag 0                ↓            →→→→→→→→ ↓           ↑       |
 * | ↑            recebe     <←←←←←←←←←←←←←←←←←←←←←←←  ( envia tarefa    ou     avisa final )  ↑       |
 * | ↑            ↙   ↘                                        x                      0                |
 * | ↑       x  ↙       ↘  0                                                          ↓                |
 * | ↑         ↓          →→→→↘                                                       ↓                |
 * |  ↖ <←←← tarefado       se final                                                  ↓                |
 * |                           ↓                                                     ↙                 |
 * |                           ↓   (sai do loop)                                   ↙                   |
 * |                           ↓                                                 ↙                     |
 * |                  retorna resultados    →→→→→→→→→→→→→→→→→→>   recebe resultados                    |
 * |                           ↓                                         ↓                             |
 * |                           ↓                                         ↓                             |
 * |                       finaliza                                Junta resultados                    |
 * |                                                                     ↓                             |
 * |                                                                     ↓                             |
 * |                                                                 finaliza                          |
 * \                                                                                                   |
 *  ---------------------------------------------------------------------------------------------------
 */

#include <limits.h>
#include <mpi.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // medir clock
#include <unistd.h>

#define MASTER 0

// queue functions
#define EMPTY_Q(q) ((q)->first == NULL)
#define CREATE_QUEUE(q)  \
   ({                    \
      (q)->first = NULL; \
      (q)->end_q = NULL; \
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

task_type *remove_q(queue *q);
bool insert_q(queue *q, char action, long num);
// void exibir_fila(queue *q);

void worker(int world_id) {
   // printf("Worker %d OK :)\n", world_id);
   // int flag = 1;
   long sum = 0, odd = 0, min = LONG_MAX, max = LONG_MIN, num_task = 1;

   MPI_Request request = MPI_REQUEST_NULL;

   MPI_Barrier(MPI_COMM_WORLD);

   while (num_task != 0) {
      // avisa que está ocioso
      // printf("\n[Worked] (%d) enviando ocioso\n", world_id);
      MPI_Send(&world_id, 1, MPI_INT, MASTER, 1, MPI_COMM_WORLD);
      // MPI_Isend(&world_id, 1, MPI_INT, MASTER, 1, MPI_COMM_WORLD, &request);

      // MPI_Wait(&request, MPI_STATUS_IGNORE);
      // printf("[Worked] (%d) enviado\n", world_id);
      MPI_Recv(&num_task, 1, MPI_LONG, MASTER, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);

      // printf("[Worked] (%d) Recebeu Task\n", world_id);
      if (num_task > 0) {
         int sleep_i = num_task;
         sleep(sleep_i);
         sum += num_task;

         if (num_task % 2 == 1) {
            odd += 1;
         }
         if (num_task < min) {
            min = num_task;
         }
         if (num_task > max) {
            max = num_task;
         }
      }
   }

   // // enviar vetor final com os resultados
   long retorno[] = {sum, odd, min, max};

   MPI_Send(&retorno, 4, MPI_LONG, MASTER, 0, MPI_COMM_WORLD);
   // //MPI_Isend(&retorno, 4, MPI_LONG, MASTER, 0, MPI_COMM_WORLD, &request);
}

void master(int world_rank, int count_worker) {
   char action, *name_file = "./test/test3.txt";
   long sum = 0, odd = 0, min = LONG_MAX, max = LONG_MIN, num;
   int world_id, ready;
   queue q;

   FILE *fin = fopen(name_file, "r");
   if (!fin) {
      printf(
          "\nErro ao abrir arquivo!\nVerifique o caminho/nome do arquivo\n\n");
      exit(EXIT_FAILURE);
   }

   MPI_Request request = MPI_REQUEST_NULL;
   // MPI_Request requests[3];// = MPI_REQUEST_NULL;
   //  MPI_Status status;
   int lineFile = 0;
   CREATE_QUEUE(&q);
   while (fscanf(fin, "%c %ld\n", &action, &num) == 2) {
      lineFile++;
   }

   fseek(fin, 0, SEEK_SET);

   MPI_Barrier(MPI_COMM_WORLD);
   int qtd = 0;

   char buffer[lineFile][2];
   // tarefa[x] = task
   // tarefa[y] = 'p' ou 'e'
   // p = 0
   // e = 1
   // p[0][0] = num task
   // p[0][1] = 'p' ou 'e'

   int u = 0;

   while (fscanf(fin, "%c %ld\n", &action, &num) == 2) {
      if (action == 'e' || action == 'p') {
         buffer[u][0] = num;
         buffer[u][1] = action;
      } else {
         printf("ERROR: Unrecognized action: '%c'\n", action);
         exit(EXIT_FAILURE);
      }
      u++;
   }
   fclose(fin);

// printf("Valores: \n");
// for (int i = 0; i < lineFile; i++){
//    printf("%c %ld\n", buffer[i][1], buffer[i][0]);
// }

// printf("\t-fim-\n");
#define FALSE 0
#define TRUE 1

   int flagEOF = FALSE;
   int index = FALSE;

   while (!flagEOF) {
      long task = buffer[index][0];
      char action = buffer[index][1];
      int recebidoInterno = 0;

      insert_q(&q, action, task);

      MPI_Irecv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD,
                &request);

      MPI_Test(&request, &ready, MPI_STATUS_IGNORE);
      if (!ready) {
         // segue a leitura

         int flagInterno = FALSE;
         int readyInt;

         while (!flagInterno) {
            recebidoInterno = FALSE;
            index++;

            if (index == lineFile) {
               flagEOF = TRUE;
               break;
            }

            long taskInt = buffer[index][0];
            char actionInt = buffer[index][1];

            if (actionInt == 'p') {
               insert_q(&q, actionInt, taskInt);
            } else {
               int sleep_i = taskInt;
               // printf("[Mestre] Dormindo %d\n", sleep_i);
               sleep(sleep_i);
            }

            MPI_Test(&request, &readyInt, MPI_STATUS_IGNORE);
            if (readyInt) {
               flagInterno = TRUE;
               recebidoInterno = TRUE;
               // recebeu
            }
         }
      } else {
         task_type *task = remove_q(&q);
         // printf("[Mestre] Enviando para (%d)- %ld\n", world_id, task->num);
         MPI_Send(&task->num, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
      }

      if (recebidoInterno) {
         task_type *task = remove_q(&q);
         // printf("[Mestre] Enviando para (%d)- %ld\n", world_id, task->num);
         MPI_Send(&task->num, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
      }

      if (flagEOF) {
         // printf("[Mestre] Aguardando\n");
         MPI_Wait(&request, MPI_STATUS_IGNORE);
         task_type *task = remove_q(&q);
         // printf("[Mestre] Enviando para (%d) - %ld\n", world_id, task->num);
         MPI_Send(&task->num, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
      }

      index++;
      if (index >= lineFile) flagEOF = TRUE;
   }

   // printf("Parte meio \n");

   while (!EMPTY_Q(&q)) {
      task_type *task = remove_q(&q);  // se pa block aqui

      MPI_Recv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);

      // printf("\nEnviando para Worker %d - Num: %ld\n", world_id, task->num);
      MPI_Send(&task->num, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
   }

   // printf("Parte final\n\n");
   for (int i = 1; i <= count_worker; i++) {
      long retorno[4];
      long flag = 0;

      MPI_Recv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      // printf("\nEnviando p Worker %d!\n", world_id);
      MPI_Send(&flag, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
      // MPI_Isend(&flag, 1, MPI_LONG, i, 0, MPI_COMM_WORLD, &request);
      // printf("Worker %d Finalizou\n", world_id);

      MPI_Recv(&retorno, 4, MPI_LONG, world_id, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      // MPI_Irecv(&retorno, 4, MPI_INT, i, 0, MPI_COMM_WORLD, &request);

      sum += retorno[0];
      odd += retorno[1];

      if (min > retorno[2]) min = retorno[2];

      if (max < retorno[3]) max = retorno[3];
   }

   printf("%ld %ld %ld %ld\n", sum, odd, min, max);
}

int main(int argc, char **argv) {
   int count_worker;

   MPI_Init(&argc, &argv);

   int world_rank;
   int world_size;

   MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
   MPI_Comm_size(MPI_COMM_WORLD, &world_size);

   count_worker = world_size - 1;

   if (world_rank != MASTER) {
      worker(world_rank);
   }

   if (world_rank == MASTER) {
      master(world_rank, count_worker);
   }

   MPI_Finalize();

   return 0;
}

bool insert_q(queue *q, char action, long num) {
   task_type *p;
   p = malloc(sizeof(task_type));

   if (p == NULL) return false;

   p->action = action;
   p->num = num;
   p->next = NULL;

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

/*  Marcar tempo
 *    clock_t begin = clock();
 *    clock_t end = clock();
 *    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 *    printf("Tempo Espera = %f\n\n", time_spent);
 */

/* flagCabouArquivo = 0
 *
 * cabou o arquivo
 *    flagCabouArquivo = 1
 *
 * percorrer o vetor
 * adiciona na fila
 * verifica se tem ocioso
 * se nao
 *    continua lendo o vetor
 *
 *    acabou arquivo
 *       flagCabouArquivo = 1
 *       break
 *
 *    se for p
 *       adiciona na fila
 *    se for e
 *       dorme
 *
 *    verifica se teve resposta
 *    se nao
 *       continua o loop
 *    se teve
 *       sai do laço
 * se tiver
 *    retira da fila e envia
 *
 */
