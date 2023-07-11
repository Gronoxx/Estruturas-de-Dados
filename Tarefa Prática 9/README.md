Nesta atividade vamos incentivar os alunos a pensarem em novos critérios de balanceamento para as árvores binárias de pesquisa. 


As árvores AVL são árvores binárias de pesquisa balanceadas que respeitam o seguinte critério de balanceamento: “A diferença entre as alturas das sub-árvores direita e esquerda é no máximo 1”. Essa propriedade impede a degeneração da estrutura da árvore de pesquisa e mantém a altura da árvore limitada a O(log n). 


Esta não é a única forma de manter uma árvore balanceada, existem outras estruturas de árvores que mantém o balanceamento através de outras regras, por exemplo:


A diferença de altura entre as sub-árvores direita e esquerda é no máximo 2 

A diferença entre a quantidade de nós nas sub-árvores direita e esquerda é no máximo 1.

A razão entre as alturas das sub-árvores direita e esquerda é no máximo 2


Os alunos deverão apresentar um critério de balanceamento para uma árvore binária de pesquisa e indicar como esse critério pode ser mantido, isto é, como os algoritmos de inclusão e remoção devem ser modificados para manter o critério escolhido.


Os alunos devem seguir o seguinte roteiro para essa prática:


Apresentar um critério de balanceamento para as árvores binárias de pesquisa;

Explicar porque o critério escolhido realmente balanceia a árvore.

Indicar os segmentos de código (linhas de código) que tem que ser reavaliadas tendo em vista o critério escolhido.

Descrever a modificação necessária para o algoritmo de inclusão para manter a árvore satisfazendo o critério escolhido.

Descrever a modificação necessária para o algoritmo de remoção para manter a árvore satisfazendo o critério escolhido.

Implementar as modificações apresentadas nos pontos anteriores.

Comparar com a AVL original em termos do número de rotações para um conjunto de operações de inserções e retiradas.

Os alunos devem entregar essa atividade prática em duas etapas: A primeira etapa deve ter sido concluída no horário da aula, quando deve ter sido apresentado um arquivo de texto com os itens 1, 2 e 3. Esta tarefa compreende a execução e documentação dos demais itens.


Para a entrega desta tarefa, os alunos devem entregar um projeto em C ou C++.


Você DEVE utilizar a estrutura de projeto abaixo junto ao Makefile :


- TP

     |- src

     |- bin

     |- obj

     |- include

     Makefile


A pasta TP é a raiz do projeto; a pasta bin deve estar vazia; src deve armazenar arquivos de código (*.c, *.cpp ou *.cc); a pasta include, os cabeçalhos (headers) do projeto, com extensão *.h, por fim a pasta obj deve estar vazia. O Makefile deve estar na raiz do projeto, assim como o PDF do relatório gerado. A execução do Makefile deve gerar os códigos objeto *.o no diretório obj, e os executáveis do TP no diretório bin.


Todos os arquivos relacionados à prática de aprendizagem devem ser submetidos na atividade designada para tal no Moodle. A entrega deve ser feita em um único arquivo com extensão .zip, nomeado nome_ultimosobrenome_matricula.zip, onde nome, último sobrenome e matrícula devem ser substituídos por suas informações pessoais. O arquivo .zip deve conter e a estrutura de projeto descrita. A sua prática será testada pela execução do comando ``make run", que deve compilar o executável e executar toda a bateria de testes proposta para a atividade e mostrar os resultados.
