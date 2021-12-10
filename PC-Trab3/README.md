# Programando em Paralelo: MPI

* Universidade Estadual de Maringá
* Programação Concorrente
* Autor:
  * Gabriel Thiago H.
  * RA107774
* Dezembro 2021

## Projeto

* Trabalho 3
* Execução do algoritmo FDTD-2d
* Utilizando UDP, SMP e MPI

## Install:
 * UDP
 * SMP
 * MPI
 * UPC

## Descrição:

  * Códigos em ./source
  Sendo então,

    * fdtd-2d_seq.c = o código sequencial, padrão do PolyBench
    * fdtd-2d.upc   = o código paralelizado, utilizado para as gerações de cada networks

    * Os arquvios polybench.c/h e fdtd-2d.h são auxiliares para a execução e definições.

  * O script é o utilizado para a geração dos testes, o qual realiza para 2, 4, 6 e 8 thread a compilação e execução dos tipos de paralelo, e o sequencial, levando os seus resultados na pasta ./resultados/<tipo>.

  * Tendo também o Makefile definido dentro de ./source para compilações padrões
  
  Note: o caminho referenciado para upcc é sendo "/usr/local/berkeley_upc/bin/", para alterar deve-se altear no script/makefile em si.