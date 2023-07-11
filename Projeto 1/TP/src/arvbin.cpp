#include "../include/arvbin.hpp"
#include <iostream>
#include <sstream>
long double ConverteString_Num(std::string s){
    std::istringstream iss(s);
    long double num;
    iss >> num;
    return num;
}
ArvoreBinaria::ArvoreBinaria()
{
raiz = NULL;
}
void ArvoreBinaria::ArvoreBinariaBasica(TipoNo* r, TipoNo* e, TipoNo* d)
{
raiz= r;
raiz->esq = e;
raiz->dir = d;
}
ArvoreBinaria::~ArvoreBinaria()
{
Limpa();
}
TipoNo* ArvoreBinaria::Insere(std::string item,TipoNo*p){
    if(p==NULL){
    p = new TipoNo();
    p->item = item;
    raiz=p;
    }
    return raiz;
}
TipoNo* ArvoreBinaria::InsereE(std::string item,TipoNo*p){
    p->esq = new TipoNo();
    p->esq->item = item;
    return p->esq;
}
TipoNo* ArvoreBinaria::InsereD(std::string item,TipoNo*p){
    p->dir = new TipoNo();
    p->dir->item = item;
    return p->dir;
}
void ArvoreBinaria::Limpa(){
ApagaRecursivo(raiz);
raiz = NULL;
}
void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
if(p!=NULL){
ApagaRecursivo(p->esq);
ApagaRecursivo(p->dir);
delete p;
}
}
void ArvoreBinaria::Imprimir(TipoNo *p){
 //In-Ordem   
 if(tipo=="INFIXA"){  
    if(p!=NULL){
    std::cout<<"( ";
    Imprimir(p->esq);
    if(isdigit(p->item[0]))
    std::cout<<p->item;
    else
    std::cout<<" "<<p->item<<" ";
    Imprimir(p->dir);
    std::cout<<" )";
    }
 }
 //Pos-Ordem
 else if(tipo=="POSFIXA"){
    if(p!=NULL){
    Imprimir(p->esq);
    Imprimir(p->dir);
    std::cout<<p->item<<" ";
    }
 }
}

TipoNo* ArvoreBinaria::Get_Raiz(){
    return this->raiz;
}

void ArvoreBinaria::Set_Tipo(std::string s){
    if(s=="INFIXA"||s=="POSFIXA")
    this->tipo = s;
    else
    throw "ERRO: TENTATIVA DE ALOCAR TIPO DIFERENTE DE INFIXA E POSFIXA";
}

long double ArvoreBinaria::Resolve(TipoNo* p){
    if(p->dir==NULL && p->esq==NULL)
    return ConverteString_Num(p->item);
    long double e = Resolve(p->esq);
    long double d = Resolve(p->dir);
    if (p->item == "+") { return e + d; }
    if (p->item == "-") { return e - d; }
    if (p->item == "*") { return e * d; }
    if (p->item == "/") {
        if(d==0)
        throw "ERRO: TENTATIVA DE DIVISÃO POR 0";
        return e / d; 
        }

    //CASO NÃO FUNCIONE, sempre irá funcionar, não é necessário um erro aqui, mas apenas para não haver warning
    return -1;
}

