#ifndef ARVBIN_HPP
#define ARVBIN_HPP
#include "../include/pilha.hpp"
class ArvoreBinaria
{
private:
TipoNo *raiz;
std::string tipo;
void ApagaRecursivo(TipoNo* p);
public:
ArvoreBinaria();
void ArvoreBinariaBasica(TipoNo* r, TipoNo* e, TipoNo* d);
TipoNo* Insere(std::string item,TipoNo*p);
TipoNo* InsereE(std::string item,TipoNo*p);
TipoNo* InsereD(std::string item,TipoNo*p);
long double Resolve(TipoNo*p);
TipoNo* Get_Raiz();
void Set_Tipo(std::string);
void Imprimir(TipoNo *p);
void Limpa();
~ArvoreBinaria();
};
#endif