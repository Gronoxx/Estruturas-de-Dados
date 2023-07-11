#include "../include/fila.hpp"
Fila::Fila()
{
    tamanho=0;
    frente = 0;
    tras = 0;
}
void Fila::Enfileira(int item){
    if (tamanho == MAXTAM)
        throw "Fila Cheia!";

    itens[tras] = item;
    // fila circular
    tras = (tras + 1) % MAXTAM; 
    tamanho++;
}
int Fila::Desenfileira(){
    int aux;

    if (tamanho == 0)
        throw "Fila está vazia!";

    aux = itens[frente];
    // fila circular
    frente = (frente + 1) % MAXTAM; 
    tamanho--;

    return aux;
}
void Fila::Limpa() {
    frente = 0;
    tras = 0;
    tamanho = 0;
}
int Fila::GetTamanho(){
    return tamanho;
}
bool Fila::Vazia(){
    if(tamanho!=0)
    return false;
    else
    return true;
}
void Fila::Imprimir(int x){
    switch(x){
    case 1:
    for(int i=0;i<tamanho;i++){
        std::cout<<itens[frente+i]<<std::endl;
    }
    break;
    case 2:
    for(int i=0;i<tamanho;i++){
        std::cout<<itens[tras-i-1]<<std::endl;
    }
    break;
    }
}
Fila::~Fila(){
    Limpa();
}
