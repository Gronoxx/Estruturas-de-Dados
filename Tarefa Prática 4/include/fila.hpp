#ifndef FILA_HPP
#include <iostream>
class Fila
{
    public:
        Fila(); 
        int GetTamanho(); 
        bool Vazia(); 

        void Enfileira(int item);
        int Desenfileira();
        void Limpa();
        void Imprimir(int x);
        ~Fila();

    private:
        int tamanho;
        int frente;
        int tras;
        static const int MAXTAM = 10;
        int itens[MAXTAM];

};


#endif