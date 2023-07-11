#ifndef PILHA_HPP
#define PILHA_HPP
#include <string>
#include <iostream>
#include "tipocel.hpp"

class Pilha{
private:
    TipoCel* topo;  
public:
int tamanho; 
    TipoCel*topo2; 
    Pilha();
    void Empilha(Ponto x);
    Ponto Desempilha();
    bool Vazia();
    void Limpa();
    ~Pilha();
    Ponto Get_Item_Topo();
};
#endif