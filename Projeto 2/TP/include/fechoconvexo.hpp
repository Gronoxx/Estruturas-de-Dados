#ifndef FECHO_CONVEXO_HPP
#define FECHO_CONVEXO_HPP
#include "ponto.hpp"
class fechoconvexo
{
    public:
    void Inserir(Ponto item);
    void Limpa();
    void Imprimir();

    int size=0;
    Ponto pontos_fecho[10000];
};
#endif