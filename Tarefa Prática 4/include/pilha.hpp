#ifndef PILHA_HPP
#include "fila.hpp"
class Pilha
{
    public:
        Pilha();
        int GetTamanho() ;
        bool Vazia() ;

        void Empilha(int item);
        int Desempilha();
        void Limpa();
        ~Pilha();
        void Imprimir();

    private:
    //Não há nenhum tipo de armazenamento interno dos dados da pilha, tudo feito pela fila!!!
        int tamanho;
        int topo;
        static const int MAXTAM = 10;
        Fila f1,f2;
        int aux_p_fila; // define qual fila é principal e qual é auxiliar

};

#endif
