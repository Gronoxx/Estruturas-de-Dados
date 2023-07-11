#include "../include/pilha.hpp"

Pilha::Pilha()
{
    tamanho=0;
    topo = -1;
    aux_p_fila=1;
}
void Pilha::Empilha(int item){
    if (tamanho==MAXTAM)
    throw "A pila está cheia";
    topo++;
    if(aux_p_fila==1)
    f1.Enfileira(item);
    if(aux_p_fila==-1)
    f2.Enfileira(item);
    tamanho++;
}
int Pilha::Desempilha(){
    int aux=0;
    //troca a fila principal
    if(tamanho==0)
    throw "A pilha está vazia";
    //passa para a outra fila para armazenar tudo que seria perdido na tentativa de acessar o item que desejamos retirar, mas 
    // a fim de não ter que repassar tudo de volta para a fila 1 apenas trocamos de fila principal
    if(aux_p_fila==1){
    while(f1.GetTamanho()>1)
    f2.Enfileira(f1.Desenfileira());
    aux=f1.Desenfileira();
    }
    if(aux_p_fila==-1){
    while(f2.GetTamanho()>1)
    f1.Enfileira(f2.Desenfileira());
    aux=f2.Desenfileira();
    }
    aux_p_fila = aux_p_fila*-1; 
    return aux;
}
int Pilha::GetTamanho(){
    return tamanho;
}
bool Pilha::Vazia(){
    if(tamanho!=0)
    return false;
    else return true;
}
void Pilha::Limpa(){
    topo=-1;
    tamanho=0;
    aux_p_fila=1;
}
void Pilha::Imprimir(){
    //Apesar da implementação ser baseada em Filas na impressão é necessário inverter a ordem, pois como
    //tudo está armazenado em filas a pilha deve ser impressa ao contrario
    std::cout<<"Fila Interna Principal\n"<<std::endl;
    if(aux_p_fila==1){
        std::cout<<"Frente"<<std::endl;
        f1.Imprimir(1);
        std::cout<<"Tras"<<std::endl;
    }
     if(aux_p_fila==-1){
        std::cout<<"Frente"<<std::endl;
        f2.Imprimir(1);
        std::cout<<"Tras"<<std::endl;
    }
    std::cout<<"\n\nPilha\n"<<std::endl;
    if(aux_p_fila==1){
        std::cout<<"Topo"<<std::endl;
        f1.Imprimir(2);
        std::cout<<"Final"<<std::endl;
    }
     if(aux_p_fila==-1){
        std::cout<<"Topo"<<std::endl;
        f2.Imprimir(2);
        std::cout<<"Final"<<std::endl;
    }
     std::cout<<"\n------------------------------\n"<<std::endl;
}
Pilha::~Pilha(){
    Limpa();
}




