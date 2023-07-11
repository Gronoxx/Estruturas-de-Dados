#include "../include/arvoremapabinaria.hpp"
#include <fstream>
#include <cmath>


int height(No_mapa *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

No_mapa *rightRotate(No_mapa *y)
{
    No_mapa *x = y->esquerda;
    No_mapa *T2 = x->direita;
 
    // Perform rotation
    x->direita = y;
    y->esquerda = T2;
 
    // Update heights
    y->height = max(height(y->esquerda),
                    height(y->direita)) + 1;
    x->height = max(height(x->esquerda),
                    height(x->direita)) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to esquerda
// rotate subtree rooted with x
// See the diagram given above.
No_mapa *leftRotate(No_mapa * x)
{
    No_mapa *y = x->direita;
    No_mapa *T2 = y->esquerda;
 
    // Perform rotation
    y->esquerda = x;
    x->direita = T2;
 
    // Update heights
    x->height = max(height(x->esquerda),   
                    height(x->direita)) + 1;
    y->height = max(height(y->esquerda),
                    height(y->direita)) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int Get_Balance(No_mapa* N) {
    if (N == nullptr)
        return 0;
    return height(N->esquerda) - height(N->direita);
}


ArvoreMapaBinaria::ArvoreMapaBinaria() : raiz(nullptr) {}

ArvoreMapaBinaria::~ArvoreMapaBinaria() {
    limpar();
}

void ArvoreMapaBinaria::inserir(std::string chave, const std::string& valor) {
    raiz = inserirNo(raiz, chave, valor);
}

bool ArvoreMapaBinaria::contem(std::string chave) {
    return encontrarNo(raiz, chave) != nullptr;
}


void ArvoreMapaBinaria::limpar() {
    limparArvore(raiz);
    raiz = nullptr;
}

No_mapa* ArvoreMapaBinaria::inserirNo(No_mapa* no, std::string chave, const std::string& valor) {
    if (no == nullptr) {
        return new No_mapa(chave, valor);
    }
    else{
    if ((chave) < (no->chave)) {
        no->esquerda = inserirNo(no->esquerda, chave, valor);
    } else if ((chave) > (no->chave)) {
        no->direita = inserirNo(no->direita, chave, valor);
    }

    no->height = 1 + max(height(no->esquerda), height(no->direita));

    int balanceFactor = Get_Balance(no);

    // Perform rotations if the tree is unbalanced
    if (balanceFactor > 1 && chave < no->esquerda->chave) {
        return rightRotate(no);
    }

    if (balanceFactor < -1 && chave > no->direita->chave) {
        return leftRotate(no);
    }

    if (balanceFactor > 1 && chave > no->esquerda->chave) {
        no->esquerda = leftRotate(no->esquerda);
        return rightRotate(no);
    }

    if (balanceFactor < -1 && chave < no->direita->chave) {
        no->direita = rightRotate(no->direita);
        return leftRotate(no);
    }

    }

    return no;
}

No_mapa* ArvoreMapaBinaria::encontrarNo(No_mapa* no, std::string chave) {
    if (no == nullptr || no->chave == chave) {
        return no;
    }

    if (chave < no->chave) {
        return encontrarNo(no->esquerda, chave);
    } else {
        return encontrarNo(no->direita, chave);
    }
}


No_mapa* ArvoreMapaBinaria::encontrarMinimo(No_mapa* no) {
    if (no == nullptr || no->esquerda == nullptr) {
        return no;
    }

    return encontrarMinimo(no->esquerda);
}

void ArvoreMapaBinaria::limparArvore(No_mapa* no) {
    if (no == nullptr) {
        return;
    }

    limparArvore(no->esquerda);
    limparArvore(no->direita);
    delete no;
}

No_mapa * ArvoreMapaBinaria::Get_raiz(){
    return this->raiz;
}
std::string ArvoreMapaBinaria::Encontrar_Valor(std::string chave) {
    No_mapa* no = raiz;
        while (no != nullptr) {
        if ((chave) < (no->chave)) {
            no = no->esquerda;
        } else if ((chave) > (no->chave)) {
            no = no->direita;
        } else {
            // Chave encontrada
            return no->valor;
        }
    }
    

    std::cout<<"Valor não encontrado, chave procurada:  "<<chave<<std::endl;
    // Chave não encontrada, retornar uma string vazia ou lançar uma exceção, conforme necessário
    return "";
}







