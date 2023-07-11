Nesta atividade prática você vai modularizar um código inicialmente monolítico. Esse código realiza operações em matrizes, nominalmente soma, multiplicação e transposição de matrizes.

O programa executável pode receber os seguintes parâmetros na linha de comando:

matop
    -s     (somar matrizes)
    -m     (multiplicar matrizes)
    -t     (transpor matriz)
    -c <arq>     (cria matriz e salva em arq)
    -x <int>    (primeira dimensao)
    -y <int>    (segunda dimensao)

A partir do arquivo matnomod.c (em anexo), você deve criar os seguintes arquivos e organizá-los como um projeto:

- mat.c e mat.h, que definem e implementam o TAD matriz.
- msgassert.h, que define as macros de erro e aviso
- matop.c, que implementa o programa principal, leitura de linha de comando e outras funções que não fazem sentido no TAD matriz.

A sua modularização deve buscar satisfazer os seguintes elementos:

- Componentização

- Interface

- Especificação

- Implementação

Você deve utilizar a linguagem C ou C++ para o desenvolvimento do seu sistema. O uso de estruturas pré-implementadas pelas bibliotecas-padrão da linguagem ou terceiros é terminantemente vetado. Caso seja necessário, use as estruturas que você implementou nos Trabalhos Práticos anteriores para criar suas próprias implementações para todas as classes, estruturas de dados, e algoritmos.

Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :

    - TP
        |- src
        |- bin
        |- obj
        |- include
        Makefile

A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e o executável do TP no diretório bin.


Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o executável e executar três comandos:

1. ./matop -s -x 5 -y 5

2. ./matop -m -x 5 -y 5

3. ./matop -t -x 5 -y 5
