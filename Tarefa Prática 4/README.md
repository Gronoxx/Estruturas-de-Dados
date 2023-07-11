Uma propriedade interessante de estruturas de dados básicas é que é possível implementar uma estrutura de dados básica usando outra estrutura de dados básica. Por exemplo, é possível implementar uma fila usando pilhas e uma pilha usando filas.

Nesta prática você vai exercitar essa interoperabilidade implementando uma pilha a partir de filas circulares. Ou seja, você deve implementar as operações criapilha, pilhavazia, empilha, desempilha e destroipilha apenas utilizando uma ou mais estruturas de dados fila circular.

Você pode utilizar qualquer implementação do TAD fila circular, inclusive a apresentada em aula.

Demonstre a correção do seu programa utilizando um domínio de 10 elementos, os dígitos de 0 a 9, que devem ser empilhados e desempilhados aleatoriamente.

Você deve utilizar a linguagem C ou C++ para o desenvolvimento do seu sistema. O uso de estruturas pré-implementadas pelas bibliotecas-padrão da linguagem ou terceiros é terminantemente vetado. Caso seja necessário, use as estruturas que você implementou em tarefas anteriores para criar suas próprias implementações para todas as classes, estruturas de dados, e algoritmos.

Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :

    - TP
        |- src
        |- bin
        |- obj
        |- include
        Makefile

A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e o executável no diretório bin.

Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o programa e executar a demonstração do domínio de 10 dígitos.
