
#include "../include/pilha.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    Pilha p;
    int num1;
    srand(time(NULL)); // define a semente inicial com o valor do relógio
    for(int i=0;i<10;i++){
    num1=rand() % 2 + 1; // gera um número aleatório entre 1 e 2
    if(num1==1){
    cout<<"Empilhar: "<<i<<endl;
    p.Empilha(i);
    }
    if(num1==2){
    try{
    cout<<"Desempilhar"<<endl;
    p.Desempilha();
    }
    catch(const char * msg){
        std::cout<<"!!!!!ERRO:"<<msg<<std::endl;
    }
    }
    p.Imprimir();
    }
    return 0;
}