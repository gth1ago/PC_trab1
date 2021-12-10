default:help

path_upcc  := /usr/local/berkeley_upc/bin/upcc
path_uprun := /usr/local/berkeley_upc/bin/upcrun

file_seq   := fdtd-2d_seq.c
file_udp   := fdtd-2d.upc

name_seq   := sequencial
name_smp   := upc_smp
name_udp   := upc_udp
name_mpi   := upc_mpi

targets    := seq \
				  smp \
				  udp	\
				  mpi

seq:
	@echo -e '\nCompilando Sequencial'
	@gcc -O0 $(file_seq) -o $(name_seq)
	@echo -e 'Criado executável: "$(name_seq)"'

smp:
	@echo -e '\nCompilando SMP'
	@$(path_upcc) $(file_udp) -T 4 --network=smp -o $(name_smp)
	@echo -e 'Criado executável: "$(name_smp)"'

udp:
	@echo -e '\nCompilando UDP'
	@$(path_upcc) $(file_udp) -T 4 --network=udp -o $(name_udp)
	@echo -e 'Criado executável: "$(name_udp)"'

mpi:
	@echo -e '\nCompilando UDP'
	@$(path_upcc) $(file_udp) -T 4 --network=mpi -o $(name_mpi)
	@echo -e 'Criado executável: "$(name_mpi)"'

all:
	@make $(targets)
	
help:
	@echo -e '\nCompilações \nmake all \nmake seq = sequencial \nmake smp = smp \nmake udp = udp \nmake mpi'
	@echo -e 'Para então criações se seus devidos executáveis!\n'

clean:
	@echo -e '\nRemovendo executaveis: $(name_seq), $(name_smp), $(name_udp) e $(name_mpi)!\n'
	@rm -f $(name_seq) $(name_smp) $(name_udp) $(name_mpi)