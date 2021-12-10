#!/bin/bash

# inic='\033[31m #####  ####### \033[0m#     #    #       #     #####  #######\n\033[31m#     #    #    \033[0m#     #   ##      # #   #     # #     #\n\033[31m#         \033[0m #    #     #  # #     #   #  #       #     #\n\033[31m#  ####    \033[0m#    #######    #    #     # #  #### #     #\n\033[31m#     #    #    \033[0m#     #    #    ####### #     # #     #\n\033[31m#     #    #    #     #    #\033[0m    #     # #     # #     #\n\033[31m #####     #    #     #  #####  #     \033[0m#  #####  #######\n'
 
# echo -e "$inic"
# Executaveis:
#  sequencial
#  upc_smp
#  upc_udp

echo -e "Iniciando..."

#cd source
#make all
mkdir -p ./resultados

caminho_upc="/usr/local/berkeley_upc/bin/"

name_seq="sequencial"
name_smp="upc_smp"
name_udp="upc_udp"

# thread 2 4 6 8
echo -e "\nRealizando: Sequencial"
gcc -O0 ./source/fdtd-2d_seq.c -o $"name_seq"
time (./$"name_seq" > resp) 2> times
grep "real" times > aux
RESUL=$(cut -c6-13 aux)
echo -e "Sequencial \t Time: $(echo $RESUL)\n" >> ./resultados/sequencial

for thread in $(seq 2 2 8); 
do
   echo -e "Realizando: T $thread - SMP"
   $"caminho_upc"upcc ./source/fdtd-2d.upc -T $thread  --network=smp -o $"name_smp"
   time ($"caminho_upc"upcrun $"name_smp" > resp) 2> times
   grep "real" times > aux
   RESUL=$(cut -c6-14 aux)
   echo -e "UDP - Thread: $thread \t Time: $(echo $RESUL)\n" >>  ./resultados/smp

   echo -e "Realizando: T $thread - UDP"
   export UPC_POLITE_SYNC=0
   $"caminho_upc"upcc ./source/fdtd-2d.upc -T $thread  --network=udp -o $"name_udp"
   time ($"caminho_upc"upcrun --localhost $"name_udp" > resp) 2> times
   grep "real" times > aux
   RESUL=$(cut -c6-14 aux)
   echo -e "UDP - Thread: $thread \t Time: $(echo $RESUL)\n" >> ./resultados/udp

   echo -e "Realizando: T $thread - MPI"
   $"caminho_upc"upcc ./source/fdtd-2d.upc -T $thread  --network=mpi -o $"name_mpi"
   time ($"caminho_upc"upcrun $"name_mpi" > resp) 2> times
   grep "real" times > aux
   RESUL=$(cut -c6-14 aux)
   echo -e "MPI - Thread: $thread \t Time: $(echo $RESUL)\n" >> ./resultados/mpi

done

echo -e "\nFinalizando.."
rm -rf aux times resp $"name_smp" $"name_udp" $"name_mpi" $"name_seq"
echo -e "Completo!\nResultados em ./resultados/\n"