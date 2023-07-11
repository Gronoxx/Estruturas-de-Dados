#include "../include/fechoconvexo.hpp"
void fechoconvexo::Limpa(){   
    for(int i=0;i<size;i++){
        pontos_fecho[i].x=0;
        pontos_fecho[i].y=0;
        pontos_fecho[i].pa=0;
    }
    size=0;
}
void fechoconvexo::Imprimir(){
    for(int i=size-1;i>=0;i--){
        std::cout<<"Ponto: ("<<pontos_fecho[i].x <<" "<<pontos_fecho[i].y<<")"<<std::endl;
    }
}
void fechoconvexo::Inserir(Ponto item){
    if(size<10000){
    pontos_fecho[size]=item;
    size++;
    }
}