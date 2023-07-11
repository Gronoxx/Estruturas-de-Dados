#include "../include/pilha.hpp"
Pilha::Pilha(){
    topo = NULL;
    tamanho=0;
}
void Pilha::Empilha(TipoNo* x){
    TipoCel * novo;
    novo = new TipoCel(x);
    novo->Set_Ant(this->topo);
    topo = novo;
    tamanho++;
}
TipoNo* Pilha::Desempilha(){
    TipoNo* aux;
    TipoCel *p;
    if(tamanho==0)
    throw "A pilha está vazia";
    aux= topo->Get_Item();
    p=topo;
    topo = topo->Get_Ant();
    delete p;
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
TipoNo* Pilha::Get_Item_Topo(){
    return topo->Get_Item();
}
bool Pilha::Vazia()
{
    if(tamanho==0)
    return true;
    else
    return false;
}
