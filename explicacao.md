Obs. sec.
    ganhar experiência na implementação de um modelo
    de fila de tarefas mestre/trabalhador de computação paralela


O programa lê uma lista de "tarefas" de um arquivo. 
Cada tarefa consiste em um código de caractere que indica uma ação e um número. 
    p = processar
    e = esperar

"processar" n = esperar n segundos => sleep 
e então atualizar algumas variáveis agregadas globais 
    soma            = dos processos
    contagem ímpar  = qtd de impar
    mínimo          = num. minimo
    máximo          = maior num.
    
A ação "e" simula uma pausa nas tarefas de entrada

--------------------------------------------------------------------------------
Inicio
Thread mestre gera um número de threads de trabalho (parâmetro exec)

Os threads de trabalho estão inativos no início. 
Uma vez que os trabalhadores tenham sido totalmente inicializados
O mestre começa a lidar com as tarefas do arquivo de entrada adicionando-os a
uma fila de tarefas, ativando um thread de trabalho ocioso (se houver) para cada tarefa

Quando um thread é ativado, eles começam a puxar tarefas da fila e processá-las. 

Se a fila ficar sem tarefas, o trabalhador deve bloquear novamente até ser acordado pelo mestre.

Se o mestre encontrar um comando "e" (esperar), ele aguardará o número determinado de segundos antes de continuar no arquivo de entrada.

Depois que todas as tarefas foram adicionadas à fila, o mestre espera que a fila
se esgote, ativando os threads inativos conforme necessário para ajudar. 

Quando a fila está vazia, o mestre espera que os trabalhadores não ociosos terminem e, em seguida, define um sinalizador global para indicar que todo o programa foi concluído

Reativando todos os threads de trabalho para que possam ser encerrados

O mestre então limpa tudo e sai.
--------------------------------------------------------------------------------

Utilizar
    thread de pthread
    mutexes
    condições

    qtd. thread por linha de comando

    >= 1 mutex
    >= condição
    manter estrutura de dados da fila de tarefas explicita


?? o desempenho em cargas de trabalho paralelizáveis
?? deve ser escalonado linearmente com o número de threads.


Dicas

• Adicione uma nova função de thread de trabalho para a maior parte da 
    sincronização do lado do trabalhador
• Implemente a fila de tarefas como uma lista ligada individualmente.
• Use um mutex para proteger as variáveis agregadas globais.
• Use um mutex para proteger a fila de tarefas.
• Use uma condição para bloquear e despertar threads de trabalho e considere o uso de seu mutex associado
    para proteger um contador de "thread inativo"

• Declare variáveis que você não deseja que o compilador otimize usando a palavra-chave volatile
• Não se esqueça dos loops do/while
• Está tudo bem para o thread mestre utilizar espera-ocupada.
• Compile com -O0 para depurar e mude para -O2 depois de ter certeza de que o básico está
    funcionando
• Crie vários arquivos de entrada de teste e um script para executar automaticamente (e 
    cronometrar) todos eles.
• Tente remover a chamada para "dormir" na função de atualização para comprimir os tempos
    de trabalho e verificar as condições de corrida.
• Não exagere na engenharia! Quanto menor o código melhor.


criterios de avacailiao
