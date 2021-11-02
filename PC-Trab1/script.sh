#!/bin/bash

# inic='\033[31m #####  ####### \033[0m#     #    #       #     #####  #######\n\033[31m#     #    #    \033[0m#     #   ##      # #   #     # #     #\n\033[31m#         \033[0m #    #     #  # #     #   #  #       #     #\n\033[31m#  ####    \033[0m#    #######    #    #     # #  #### #     #\n\033[31m#     #    #    \033[0m#     #    #    ####### #     # #     #\n\033[31m#     #    #    #     #    #\033[0m    #     # #     # #     #\n\033[31m #####     #    #     #  #####  #     \033[0m#  #####  #######\n'
 
# echo -e "$inic"

echo -e "Iniciando..."

make all
mkdir -p resultados

# entrada1..5 com thread 1..4
for arq_sq in $(seq 1 5); 
do
   echo ' ' > resultados/entrada$arq_sq
   echo -e "\nRealizando: Sequencial \t F entrada$arq_sq"
   time (./sum entrada/entrada$arq_sq.txt > resp) 2> times
   sed '1d;3,$d' times > aux
   RESUL=$(cut -c6-13 aux)
   echo -e "Sequencial \t File: entrada$arq_sq.txt \t Time: $RESUL \t Resposta: $(cat resp)" >> resultados/entrada$arq_sq
   for thread in $(seq 1 4);
   do 
      echo -e "Realizando: T $thread \t F entrada$arq_sq"
      time (./par_sum -t $thread -f entrada/entrada$arq_sq.txt > resp) 2> times
      sed '1d;3,$d' times > aux
      RESUL=$(cut -c6-14 aux)
      echo -e "Thread: $thread \t File: entrada$arq_sq.txt \t Time: $RESUL \t Resposta: $(cat resp)" >> resultados/entrada$arq_sq
   done
done

echo -e "\nFinalizando.."
rm -rf aux times resp
make clean
echo -e "Completo!\nResultados em ./resultados/\n"