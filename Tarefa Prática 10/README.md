Nesta atividade vamos discutir a calibração de parâmetros de uma árvore B.

Para simplificar o problema, vamos trabalhar apenas com árvores B em memória, havendo dois parâmetros fundamentais:

- m: ordem da árvore

- CARGA: tamanho do registro em bytes

Espera-se haver um compromisso entre esses parâmetros, em termos de localidade de referência temporal e espacial. Esse compromisso deve ser mais acentuado quando a estrutura de dados demandar o uso do swap.

Os alunos devem seguir o seguinte roteiro para essa prática:


Planejar um conjunto de experimentos variando os parâmetros (sugerimos realizar alguns experimentos preliminares).

Justificar porque o plano de experimentos exercita o compromisso entre os parâmetros.

Executar os experimentos planejados, medindo o tempo de execução e outros parâmetros que considerar pertinente
Analisar os resultados e elaborar um relatório.
Os alunos devem entregar essa atividade prática em duas etapas: no horário da aula devem apresentar pelo menos um arquivo de texto com os itens 1 e 2, e posteriormente devem realizar os demais itens.

Para a entrega dos demais pontos, os alunos devem entregar um projeto em C ou C++. E um relatório em PDF.

A linha de comando pode ser algo como:

gcc -Dm=2 -DCARGA=100 -o arvexp arvexp.c -lm

Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :


- TP

     |- src

     |- bin

     |- obj

     |- include

     Makefile

     Relatorio.pdf


A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto, assim como o PDF do relatório gerado. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e os executáveis do TP no diretório bin.


Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o executável e executar uma bateria de testes mais simples.
