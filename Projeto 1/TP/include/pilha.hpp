#ifndef PILHA_HPP
#define PILHA_HPP
#include <string>
#include <iostream>
#include "../include/tipocel.hpp"

class Pilha{
private:
    TipoCel* topo;
    int tamanho;    
public:
    Pilha();
    void Empilha(TipoNo* x);
    TipoNo* Desempilha();
    bool Vazia();
    void Limpa();
    ~Pilha();
    TipoNo* Get_Item_Topo();
};
#endif