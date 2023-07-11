#include "fibonacci.hpp"

int Fibonacci::recursivo(int n){
    if (n < 3)
        return 1;
    else{
        // Usado para aumentar o tempo de execução
        for (int i = 3; i < 10000000; i++) sin(i);
        
        return recursivo(n-1) + recursivo(n-2);
    }
}

int Fibonacci::iterativo(int n){
    int fn1 = 1, fn2 = 1;
    int fn, i;

    if (n < 3) return 1;
    
    for (i = 3; i <= n; i++) {
        fn = fn2 + fn1;
        fn2 = fn1;
        fn1 = fn;
    }
    return fn;
}