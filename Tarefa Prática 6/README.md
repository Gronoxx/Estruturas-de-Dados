Elabore um relatório do roteiro a seguir utilizando um programa que apresente uma complexidade de acesso à memória que permita uma caracterização. O primeiro passo já foi coberto na tarefa inicial em sala de aula e pode ser replicado no relatório.

Avalie qualitativamente o programa a ser caracterizado em termos dos acessos de memória esperados e localidade de referência. Identifique as estruturas de dados e segmentos de código críticos (p.ex., mais custosos)

Elabore o plano de caracterização de localidade de referência, nesse momento indicando as execuções e ferramentas a serem realizadas e porque.

Selecione os parâmetros do programa a ser caracterizado

Programa não deve executar por muito ou pouco tempo, mas o suficiente para entender o comportamento do algoritmo.

Execute o código com Cachegrind:

valgrind --tool=cachegrind <binário do programa> <parâmetros>

cg_annotate cachegrind.out.<número do processo do passo 1>

Execute o código com Callgrind

valgrind --tool=callgrind  <binário do programa> <parâmetros>

callgrind_annotate callgrind.out.<número do processo do passo 1>

Avalie as saídas do CacheGrind/CallGrind para responder as seguintes perguntas:

Quão bem o programa se comporta em termos de memória?

Quais estruturas de dados devem serem caracterizadas para melhor entendimento?

Quais segmentos de código devem instrumentados para suportar a caracterização?

Acrescente todas as informações, como telas, códigos e saídas que considerar pertinentes.
