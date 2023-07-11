Nesta atividade prática você vai avaliar o desempenho de códigos recursivos e não recursivos para as mesmas tarefas.

A atividade prática se divide em duas tarefas:


Tarefa 1: Cálculo de fatorial: utilize os códigos recursivos e iterativo apresentados para o cálculo de fatorial.


Tarefa 2: Número de Fibonacci: utilize os códigos recursivos e iterativo apresentados para o número de Fibonacci.


A seguir descrevemos o que deve ser feito em cada tarefa.


Codifique em linguagem C ou C++ cada versão. Para facilitar, empregue um parâmetro de linha de comando que define a tarefa a ser utilizada, nominalmente o fatorial ou o número de Fibonacci.

Descreva o seu plano de experimentos, ou seja, qual a faixa de valores para a qual as versões serão avaliadas (por exemplo, fatorial de 1 a 20). 

Meça o tempo de relógio para as várias configurações e verifique a sua correlação com a ordem de complexidade do respectivo algoritmo.

Meça os tempos de utilização de recursos (usuário e sistema) e compare com os tempos de relógio.

Para o algoritmo recursivo,  meça o tempo de execução para cada chamada usando o tempo de relógio e o gprof, compare as diferenças.

Para o algoritmo recursivo, insira, na chamada recursiva, uma função que consuma recursos computacionais (por exemplo calcule o seno de um número 1 milhão de vezes), e repita as medições do item 5.


Gere um relatório PDF com todos esses experimentos para ambas as tarefas.


Você deve utilizar a linguagem C ou C++ para o desenvolvimento. O uso de estruturas pré-implementadas pelas bibliotecas-padrão da linguagem ou terceiros é terminantemente vetado. 


Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :


- TP

     |- src

     |- bin

     |- obj

     |- include

     Makefile


A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto, assim como o PDF do relatório gerado. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e os executáveis do TP no diretório bin.


Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o executável e executar cada versão de cada algoritmo com parâmetro 5, ou seja, fatorial de 5 e número de Fibonacci de 5.

