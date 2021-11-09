# Programando em Paralelo: MPI

* Universidade Estadual de Maringá
* Programação Concorrente
* Autor:
  * Gabriel Thiago
  * RA107774
* Novembro 2021

## Projeto

* Trabalho 2
* Leitura e distribuições de processamentos para tarefas
* Utilizando MPI
* 
Install:
  Tau Commander
  MPI

Códigos em ./source

Em "analises" está as análises utilizadas
   scriptTime.sh = Script para pegar o tempo de cada processo, utilizando o MPI_Wtime() (comentadas no código)
   scriptTau.sh  = script para execução e armazenamento das saídas com a ferramenta Tau
                   As análises estão salvas em ./analises/.tau/

Vale ressaltar a instalação de TAU:

   $ sudo su
   $ wget http://fs.paratools.com/taucmdr/taucmdr-1.4.0-Linux-x86_64.tar.gz
   $ tar -xf taucmdr-1.4.0-Linux-x86_64.tar.gz

   $ cd taucmdr-1.4.0

   # instalado em /usr porém verificar a máquina
   $ make install INSTALLDIR=/usr
   $ /usr/system/configure --mpi T

   # adc no path o caminho de onde instalou 
   export PATH=/usr/bin:$PATH

   # acessa o ambiente para análise
   $ cd ./analises

   $ tau initialize --mpi T --mpit T --callsite T --comm-matrix T

   # tau mpirun -np <qtd processos> -- ./<executavel> -parametros do arquivo
   $ tau mpirun -np 6 --oversubscribe --allow-run-as-root -- ./a.out -f ../entrada/entrada3.txt

   # para visualizações das análises 
   $ tau show
   $ tau trial show
   $ tau trial show --pofile-tool pprof


