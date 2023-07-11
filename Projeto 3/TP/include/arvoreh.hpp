#ifndef ARVOREH_HPP
#define ARVOREH_HPP
#include "../include/no.hpp"
class Arvore
{
private:
No * raiz;
public:
Arvore(No * raiz);
No * Get_raiz();
void inOrder(No* node);
void posOrder(No* node);
void preOrder(No* node);
void Apagar(No*node);
~Arvore();
};
#endif