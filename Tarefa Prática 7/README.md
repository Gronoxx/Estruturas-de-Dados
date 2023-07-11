Nesta atividade vamos avaliar um algoritmo de ordenação cuja a complexidade teórica ainda não está definida, o shellsort (https://pt.wikipedia.org/wiki/Shell_sort). Esse algoritmo foi discutido na aula e ele funciona como uma modificação da ordenação por inserção e possui um parâmetro h que deve ser escolhido e calibrado de maneira correta para que esse método se comporte de forma eficiente. 

Para fazer isso, os alunos devem criar um gerador de números aleatórios e devem medir o tempo de execução do seu código comparando o mesmo com um método de ordenação eficiente, no caso dessa prática, o heapsort ou ordenação por heap.



Os alunos devem seguir o seguinte roteiro para a elaboração dessa avaliação empírica:


Planejar uma bateria de testes com diferentes valores de tamanho para os vetores a serem gerados pelo programa, assim como uma forma de analisar a performance do método de maneira significativa para o conjunto de valores de h’s escolhidos.

Implementar o heapsort (ordenação por heap) e o shellsort com sua estratégia de escolha e atualização dos h.

Implementar um gerador de vetores aleatórios

Realizar os testes descritos no ponto 1.

Apresentar um relatório em PDF com os resultados obtidos.


Os alunos devem entregar essa atividade prática em duas etapas: no horário da aula devem apresentar pelo menos um arquivo de texto com o ponto 1 e posteriormente devem realizar as demais tarefas, seguindo o planejamento especificado.


Para a entrega dos demais pontos, os alunos devem entregar um projeto em C ou C++, juntamente com um arquivo em PDF contendo a descrição dos resultados obtidos. 


Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :


- TP

     |- src

     |- bin

     |- obj

     |- include

     Makefile


A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto, assim como o PDF do relatório gerado. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e os executáveis do TP no diretório bin.



Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o executável e executar toda a bateria de testes proposta para a atividade e mostrar os resultados.

