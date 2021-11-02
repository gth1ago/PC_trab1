#!/bin/bash

# inic='\033[31m #####  ####### \033[0m#     #    #       #     #####  #######\n\033[31m#     #    #    \033[0m#     #   ##      # #   #     # #     #\n\033[31m#         \033[0m #    #     #  # #     #   #  #       #     #\n\033[31m#  ####    \033[0m#    #######    #    #     # #  #### #     #\n\033[31m#     #    #    \033[0m#     #    #    ####### #     # #     #\n\033[31m#     #    #    #     #    #\033[0m    #     # #     # #     #\n\033[31m #####     #    #     #  #####  #     \033[0m#  #####  #######\n'
 
# echo -e "$inic"

echo -e "Iniciando..."

mkdir -p perf_resul

for arq_sq in $(seq 1 5); 
do 
   echo -e "\nRealizando: Sequencial \t F entrada$arq_sq"
   echo -e ' ' > perf_resul/perf_entrada$arq_sq
   sudo perf stat -r 2 ./sum entrada/entrada1.txt >/dev/null 2>>perf_resul/perf_entrada$arq_sq
   for thread in 2 4;
   do
      echo -e "Realizando: T $thread \t F entrada$arq_sq"
      sudo perf stat -r 5 ./par_sum -t $thread -f entrada/entrada$arq_sq.txt >/dev/null 2>>perf_resul/perf_entrada$arq_sq
   done
done

echo -e "\nFinalizando.."
rm -rf aux times resp
echo -e "Completo!\nperf_resul em ./perf_resul/\n"
