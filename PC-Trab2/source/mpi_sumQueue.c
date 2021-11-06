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
 * 
 * Questao
 *    Como funciona o recebimento do MPI_Isend // Irecv
 *       primitivas - status
 *    n vi mt impacto isend irevc e wait
 *       mpi cuida boa parte dessas coisa
 *    Fila necessária (?)
 *    Somente mestre altera a fila, sem bloqueios (?)
 *    As Variaveis também
 *    0.8s deplay comparado ao threads (?)
 *    num de trab?
 *       a vontade :)
 *       so n fz merd
 *    mpirun -n 10 --oversubscribe a.out -> trab
 *       add isso de -> custo de passagem de mensagem - tem uma analise disso - envio e recebimento de msg
 *       pthread n tem passagem d msg ae n daria
 *       
 *    Referencias/Docu pra entender o desempenho especifico
 *      perf n coleta msg se pa
 *    tem uma bib.
 *       q compila junto com cod. e ae dps da execução ele mostra varias metricas analisadas (msg rec, enviada..)
 *       ele vai caça o nome da biblioteca 
 * 
 *    tempo gasto em lock, barreira, no pthread era massa, quanto maior for mais perda de des. tem
 *    ja aqui qto mais msg tiver, pior
 */

#include <limits.h>
#include <mpi.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
   //int flag = 1;
   long sum = 0, odd = 0, min = LONG_MAX, max = LONG_MIN, num_task = 1;

   MPI_Request request = MPI_REQUEST_NULL;

   while (num_task != 0) {
      // avisa que está ocioso
      MPI_Send(&world_id, 1, MPI_INT, MASTER, 1, MPI_COMM_WORLD);
      // MPI_Isend(&world_id, 1, MPI_INT, MASTER, 1, MPI_COMM_WORLD, &request);

      MPI_Recv(&num_task, 1, MPI_LONG, MASTER, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);

      if (num_task != 0) {
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
      // else 
      //  flag = 0;
   }

   // enviar vetor final com os resultados
   long retorno[] = {sum, odd, min, max};

   // MPI_Send(&retorno, 4, MPI_INT, MASTER, 0, MPI_COMM_WORLD);
   MPI_Isend(&retorno, 4, MPI_LONG, MASTER, 0, MPI_COMM_WORLD, &request);
}


void master(int world_rank, int count_worker) {
   char action, *name_file = "./test/test3.txt";
   long sum = 0, odd = 0, min = LONG_MAX, max = LONG_MIN, num;
   int world_id;
   queue q;
   // printf("Numero de trabs: %d\n", count_worker);

   FILE *fin = fopen(name_file, "r");
   if (!fin) {
      printf(
          "\nErro ao abrir arquivo!\nVerifique o caminho/nome do arquivo\n\n");
      exit(EXIT_FAILURE);
   }

   CREATE_QUEUE(&q);

   while (fscanf(fin, "%c %ld\n", &action, &num) == 2) {
      if (action == 'p' || action == 'e') {
         insert_q(&q, action, num);
      } else {
         printf("ERROR: Unrecognized action: '%c'\n", action);
         exit(EXIT_FAILURE);
      }
   }
   fclose(fin);

   //  TIME = 0.000065

   // world_id é o worker ocioso

   // MPI_Request request = MPI_REQUEST_NULL;
   // MPI_Status status;
   while (!EMPTY_Q(&q)) {
      task_type *task = remove_q(&q);

      if (task->action == 'p') {
         // MPI_Irecv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &request);
         MPI_Recv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD,
                  MPI_STATUS_IGNORE);
         // MPI_Wait(&request, &status);

         printf("Aguardando p envio\n");
         MPI_Send(&task->num, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
         // printf("\nEnviado para Worker %d - Num: %ld\n", world_id, task->num);
      } else if (task->action == 'e') {
         int sleep_i = task->num;
         printf("Mimindo!\n");
         sleep(sleep_i);
      }
   }
   // TIME = 0.000173 

   // recebe dos ocioso e avisa que acabou
   // e recebe os resultados deles
   for (int i = 1; i <= count_worker; i++) {
      long retorno[4];
      long flag = 0;

      MPI_Recv(&world_id, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      MPI_Send(&flag, 1, MPI_LONG, world_id, 0, MPI_COMM_WORLD);
      // MPI_Isend(&flag, 1, MPI_LONG, i, 0, MPI_COMM_WORLD, &request);
      //printf("Worker %d Finalizou\n", world_id);

      MPI_Recv(&retorno, 4, MPI_LONG, world_id, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      // MPI_Irecv(&retorno, 4, MPI_INT, i, 0, MPI_COMM_WORLD, &request);

      sum += retorno[0];
      odd += retorno[1];

      if (min > retorno[2]) min = retorno[2];

      if (max < retorno[3]) max = retorno[3];
      /* Tempo 1 = 15.917254 um dos work ta com +- 0.9 de delay
       * Tempo 2 = 3.921864
       * Tempo 3 = 0.000031
       * Tempo 4 = 0.000035
       * Tempo 5 = 0.000026
       * Tempo 6 = 0.000041
       * Tempo 7 = 0.000023
       * Tempo 8 = 0.000013
       * Tempo 9 = 0.000091
       */
   }
   // TIME FUNCAO = 19.788624
   // TIME TOTAL = 19.846149


   // printf("Master: %d Finalizado!\nCerto :)\n", world_rank);

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

// void exibir_fila(queue *q) {
//    task_type *aux;

//    if (q->first == NULL) {
//       printf("\tERRO: Fila vazia\n");
//       return;
//    }

//    aux = q->first;
//    printf("\nFila: ");
//    while (aux != NULL) {
//       printf(" %c - %d |", aux->action, aux->num);
//       aux = aux->next;
//    }
//    printf("\n");
// }

/* MPI_Send(&token, 5, MPI_INT, worker, 0, MPI_COMM_WORLD);
 * buf = estrutura onde recebe a mensagem, regiao q vai receber
 * count = quantidade de dados
 * datatype =
 * source = de quem vai receber (MPI_any para receber de qualquer trabalhador)
 * tag = inteiro = para gerenciar as mensagens, diferenciar as msg = opcional
 * MPI_Comm comm = comunicador, tem global, é um canal de comunicação, e um
 *             processo so consegue enviar msg d um p outro só se pertencerem ao
 * mesmo comunicador se quero criar grupo de processos, defino 2 comunicador
 * (tem a chamada p criar) no 1 coloco "5" processo e no outro tantos, ae os q
 * tao dentro d um troca msg mas do 1 nao consegue enviar para o 2, se for
 * vincular os dois grupos cria um 3 comunicador e adiciona UM processo só de
 * cada grupo, ae pode troca pros dois grupo quer enviar msg p um grupo usa o
 * dele, pra outro, uso o outro status = aviso p se chegou ao destino final
 */

/* Mestre tem a fila e envia a tarefa para os trabalhadores ociosos
 * Por sua vez os ociosos tem que avisar que estão ociosos
 * O mestre entao recebe a informação e envia para eles
 */

/* VER O TIPO DE SEND
 *
 * send com envio de buffer ou nao
 *       define o buffer que são onde os processo vao enviar/receber mensagens
 * envio bloqueante
 *    o processo so continua quando o recebedor recebe a mensagem
 *    Pq o recebedor recebe envia de volta um OK
 *    Quando ele recebe o OK a acao continua
 * envio desbloqueante
 *      Envia a mensagme e foda-se se recebeu ou nao
 *
 * Situações que usam o bloqeuanado e situações que usam o não bloqueante
 * MPI_Isend (TENTA USA ESSE, envio sem bloqueio)
 * MPI_Test
 * MPI_Wait (espera receber)
 * le os bagui d cada um p saber
 */


/*  Marcar tempo
 *    clock_t begin = clock();
 *    clock_t end = clock();
 *    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 *    printf("Tempo Espera = %f\n\n", time_spent);
 */ 