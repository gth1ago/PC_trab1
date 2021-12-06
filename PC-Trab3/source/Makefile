default:help

name_seq := sequencial
name_smp := upc_smp
name_udp := upc_udp


seq:
	@echo -e '\nCompilando Sequencial'
	@echo -e '-O0 e teste com ExtraLarge - Tempo com DPOLYBENCH_TIME'
	@gcc -O0 -I polybench-c-4.2.1-beta/utilities polybench-c-4.2.1-beta/utilities/polybench.c polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c -DPOLYBENCH_TIME -DEXTRALARGE_DATASET -o $(name_seq)
	@echo -e 'Criado executável: "$(name_seq)"'

smp:
	@echo -e '\nCompilando SMP'
	@export GASNET_PSHM_NODES=4
	@/usr/local/berkeley_upc/bin/upcc -I polybench-c-4.2.1-beta/utilities polybench-c-4.2.1-beta/utilities/polybench.c polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c --network=smp -I prallel -DEXTRALARGE_DATASET -o $(name_smp)
	@echo -e 'Criado executável: "$(name_smp)"'

udp:
	@echo -e '\nCompilando UDP'
	@/usr/local/berkeley_upc/bin/upcc -I polybench-c-4.2.1-beta/utilities polybench-c-4.2.1-beta/utilities/polybench.c polybench-c-4.2.1-beta/stencils/fdtd-2d/fdtd-2d.c --network=udp -I prallel -DEXTRALARGE_DATASET -o $(name_udp)
	@echo -e 'Criado executável: "$(name_udp)"'

help:
	@echo -e '\nCompilações \nmake seq = sequencial \nmake smp = smp \nmake udp = udp'
	@echo -e 'Para então criações se seus devidos executáveis!\n'

clean:
	@echo -e '\nRemovendo executaveis: $(name_seq), $(name_smp) e $(name_udp)!\n'
	@rm -f $(name_seq) $(name_smp) $(name_udp)