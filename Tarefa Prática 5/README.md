Os caminhamentos em árvores permitem explorar uma variedade de tarefas, inclusive quando utilizados de forma combinada.

Considere uma árvore binária, não necessariamente balanceada, contendo n nós, cada um contendo uma chave inteira, ou seja n chaves distintas que variam de 0 a n-1. Considere ainda que você implementou três caminhamentos: Pré-ordem, In-ordem e Pós-ordem. Cada caminhamento preenche um vetor de n posições, onde cada posição se refere à chave de um nó com a ordem do nó em questão em cada caminhamento. Por exemplo, a posição do vetor pré-ordem da raiz da árvore contem o valor 0, enquanto a posição do vetor pós-ordem da raiz contem o valor n-1, pois a raiz seria a primeira e a última a ser impressa, respectivamente, nos caminhamentos pré-ordem e pós-ordem. No caso do vetor in-ordem, o nó mais a esquerda da sub-árvore a esquerda contem o valor 0, pois seria o primeiro a ser impresso pelo referido caminhamento.

A sua tarefa é implementar uma função que verifica se um nó i é ancestral de um nó j usando apenas os 3 vetores gerados pelos caminhamentos. Dizemos que um nó de chave i é ancestral de um nó de chave j se o nó de chave i faz parte do caminho entre a raiz e o nó de chave j.

O programa constante dessa tarefa recebe um parâmetro, n, que é o número de nós da árvore e gera uma árvore aleatória com aproximadamente n nós. Você deve implementar os caminhamentos e executar n chamadas aleatórias da função ancestral (i,j).

Você deve utilizar a linguagem C ou C++ para o desenvolvimento do seu programa. O uso de estruturas pré-implementadas pelas bibliotecas-padrão da linguagem ou terceiros é terminantemente vetado. Caso seja necessário, use as estruturas que você implementou em tarefas anteriores para criar suas próprias implementações para todas as classes, estruturas de dados, e algoritmos.

Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :

    - TP
        |- src
        |- bin
        |- obj
        |- include
        Makefile

A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e o executável no diretório bin.

Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o programa e executar criando uma árvore de 10 nós, a qual é usada para demonstrar a função ancestral, que deve ser invocada 10 vezes.
