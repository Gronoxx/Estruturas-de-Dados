#include "fatorial.hpp"

int Fatorial::recursivo(int n){
    if (n == 0)
        return 1;
    else {
        // Usado para aumentar o tempo de execução
        for (int i = 3; i < 10000000; i++) sin(i);
        
        return n * recursivo(n-1);
    }
}

int Fatorial::iterativo(int n){
    int f;
    f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
}