#include "../include/arvoreh.hpp"
#include <iostream>
Arvore::Arvore(No* raiz){
    this->raiz=raiz;
}
No * Arvore::Get_raiz(){
    return raiz;
}

void Arvore::posOrder(No * node){
    if (node == nullptr) {
        return;
    }
    posOrder(node->esq);
    posOrder(node->dir);
    if(node->leaf==true){
        std::cout<<"Letra: "<<node->letra<<", Frequência: "<<node->freq<<std::endl;
    }
    else
    std::cout<<"Frequência: "<<node->freq<<std::endl;
}
void Arvore::preOrder(No* node){
   if (node == nullptr) {
        return;
    }
    if(node->leaf==true){
        std::cout<<"Letra: "<<node->letra<<", Frequência: "<<node->freq<<std::endl;
    }
    else
    std::cout<<"Frequência: "<<node->freq<<std::endl;
    preOrder(node->esq);
    preOrder(node->dir);
}
void Arvore::inOrder(No* node){
     if (node == nullptr) {
        return;
    }
    inOrder(node->esq);
    if(node->leaf==true){
        std::cout<<"Letra: "<<node->letra<<", Frequência: "<<node->freq<<std::endl;
    }
    else
    std::cout<<"Frequência: "<<node->freq<<std::endl;
    inOrder(node->dir);
}
void Arvore::Apagar(No*node){
    if (node != nullptr) {
            Apagar(node->esq);
            Apagar(node->dir);
            node=nullptr;
            delete node;
        }
}
Arvore::~Arvore(){
    Apagar(this->raiz);
}

