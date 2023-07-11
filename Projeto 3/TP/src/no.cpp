#include "../include/no.hpp"
No::No(char letra,bool leaf)
{   
    if(leaf==true){
    this->letra =letra;
    this->freq=0;
    }
    this->leaf=leaf;
    this->esq=nullptr;
    this->dir=nullptr;
}
