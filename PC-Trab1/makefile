default:par

name_sum := sum
name_par := par_sum

all: 
	@echo -e '\nCompilando sequencial e paralelo!\n'
	@gcc -o $(name_sum) ./source/$(name_sum).c -O2 -Wall
	@gcc -o $(name_par) ./source/$(name_par).c -pthread -O2 -Wall
	@echo -e 'Compilados!\n'

sum:
	@echo -e '\nCompilando sequencial!\n'
	@gcc -o $(name_sum) ./source/$(name_sum).c -O2 -Wall
	@echo -e 'Compilados!\n'

par:
	@echo -e '\nCompilando paralelo\n'
	@gcc -o $(name_par) ./source/$(name_par).c -pthread -O2 -Wall
	@echo -e 'Compilado!\n'

clean:
	@echo -e '\nRemovendo executaveis: $(name_sum) e $(name_par)!\n'
	@rm -f $(name_sum) $(name_par) 

help:
	@echo -e '\nConsulte nosso README para maiores informações!'
	@echo -e 'Utilize de cat/vim README.md\n'