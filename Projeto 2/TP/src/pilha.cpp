#include "../include/pilha.hpp"
Pilha::Pilha(){
    topo = NULL;
    topo2=NULL;
    tamanho=0;
}
void Pilha::Empilha(Ponto x){
    TipoCel * novo;
    novo = new TipoCel(x);
    novo->Set_Ant(this->topo);
    topo2=this->topo;
    topo = novo;
    tamanho++;
}
Ponto Pilha::Desempilha(){
    Ponto aux;
    TipoCel *p;
    if(tamanho==0)
    throw "A pilha está vazia";
    aux= topo->Get_Item();
    p=topo;
    topo = topo->Get_Ant();
    if(topo2 != NULL)
    topo2 = topo2->Get_Ant();
    delete p;
    p=nullptr;
    tamanho--;
    return aux;
}
void Pilha::Limpa(){
    while(!Vazia()){
        Desempilha();
    }
}
Pilha::~Pilha(){
    Limpa();
}
Ponto Pilha::Get_Item_Topo(){
    return topo->Get_Item();
}
bool Pilha::Vazia()
{
    if(tamanho==0)
    return true;
    else
    return false;
}
