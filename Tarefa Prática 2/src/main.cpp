#include "fatorial.hpp"
#include "fibonacci.hpp"
#include <iostream>

#include <sys/resource.h>

using namespace std;

Fibonacci fib;
Fatorial fat;

int main(int argc, char *argv[]) {
    if(argc == 1) {
        struct timespec t1, t2, res;
        struct rusage usage;
        struct timeval tmv;

        cout << "Utilização: " << argv[0] << " [-f|-b] [-r] <n>" << endl;
        cout << "  -f: fatorial" << endl;
        cout << "  -b: fibonacci" << endl;
        cout << "  -r: recursivo" << endl;
        cout << "  <n>: número" << endl;
        cout << "Exemplo: " << argv[0] << " -fr 5" << endl;
        cout << endl;

        cout << "TESTES FATORIAL E FIBONACCI:" << endl;
        cout << endl;

        cout << "========================================" << endl;
        cout << "Fatorial recursivo de 5 até 10: " << endl;
        cout << endl;
        for(int i = 5; i <= 10; i++) {
            clock_gettime(CLOCK_MONOTONIC, &t1);
            cout << "fat(" << i << ") = " << fat.recursivo(i) << endl;
            clock_gettime(CLOCK_MONOTONIC, &t2);
            if (t2.tv_nsec < t1.tv_nsec){
                // ajuste necessario, utilizando um segundo de tv_sec
                res.tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec-1;
            } else {
                // nao e necessario ajuste
                res.tv_nsec = t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec;
            }
            cout << "Tempo de execução: " << res.tv_sec << "s " << res.tv_nsec << "ns" << endl;
            getrusage(RUSAGE_SELF, &usage);
            tmv = usage.ru_utime;
            cout << "Tempo de CPU: " << tmv.tv_sec << "s " << tmv.tv_usec << "us" << endl;
            cout << "Memória utilizada: " << usage.ru_maxrss << "KB" << endl;
            cout << endl;
        }
        cout << endl;

        cout << "========================================" << endl;
        cout << "Fatorial iterativo de 5 até 16: " << endl;
        cout << endl;
        for(int i = 5; i <= 16; i++) {
            clock_gettime(CLOCK_MONOTONIC, &t1);
            cout << "fat(" << i << ") = " << fat.iterativo(i) << endl;
            clock_gettime(CLOCK_MONOTONIC, &t2);
            if (t2.tv_nsec < t1.tv_nsec){
                // ajuste necessario, utilizando um segundo de tv_sec
                res.tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec-1;
            } else {
                // nao e necessario ajuste
                res.tv_nsec = t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec;
            }
            cout << "Tempo de execução: " << res.tv_sec << "s " << res.tv_nsec << "ns" << endl;
            getrusage(RUSAGE_SELF, &usage);
            tmv = usage.ru_utime;
            cout << "Tempo de CPU: " << tmv.tv_sec << "s " << tmv.tv_usec << "us" << endl;
            cout << "Memória utilizada: " << usage.ru_maxrss << "KB" << endl;
            cout << endl;
        }
        cout << endl;

        cout << "========================================" << endl;
        cout << "Fibonacci recursivo de 5 até 10: " << endl;
        cout << endl;
        for(int i = 5; i <= 10; i++) {
            clock_gettime(CLOCK_MONOTONIC, &t1);
            cout << "fib(" << i << ") = " << fib.recursivo(i) << endl;
            clock_gettime(CLOCK_MONOTONIC, &t2);
            if (t2.tv_nsec < t1.tv_nsec){
                // ajuste necessario, utilizando um segundo de tv_sec
                res.tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec-1;
            } else {
                // nao e necessario ajuste
                res.tv_nsec = t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec;
            }
            cout << "Tempo de execução: " << res.tv_sec << "s " << res.tv_nsec << "ns" << endl;
            getrusage(RUSAGE_SELF, &usage);
            tmv = usage.ru_utime;
            cout << "Tempo de CPU: " << tmv.tv_sec << "s " << tmv.tv_usec << "us" << endl;
            cout << "Memória utilizada: " << usage.ru_maxrss << "KB" << endl;
            cout << endl;
        }
        cout << endl;

        cout << "========================================" << endl;
        cout << "Fibonacci iterativo de 5 até 20: " << endl;
        cout << endl;
        for(int i = 5; i <= 20; i++) {
            clock_gettime(CLOCK_MONOTONIC, &t1);
            cout << "fib(" << i << ") = " << fib.iterativo(i) << endl;
            clock_gettime(CLOCK_MONOTONIC, &t2);
            if (t2.tv_nsec < t1.tv_nsec){
                // ajuste necessario, utilizando um segundo de tv_sec
                res.tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec-1;
            } else {
                // nao e necessario ajuste
                res.tv_nsec = t2.tv_nsec-t1.tv_nsec;
                res.tv_sec = t2.tv_sec-t1.tv_sec;
            }
            cout << "Tempo de execução: " << res.tv_sec << "s " << res.tv_nsec << "ns" << endl;
            getrusage(RUSAGE_SELF, &usage);
            tmv = usage.ru_utime;
            cout << "Tempo de CPU: " << tmv.tv_sec << "s " << tmv.tv_usec << "us" << endl;
            cout << "Memória utilizada: " << usage.ru_maxrss << "KB" << endl;
            cout << endl;
        }
        cout << endl;

        return EXIT_SUCCESS;

    }

    if (argc < 3) {
        cerr << "Erro: número insuficiente de argumentos." << endl;
        return EXIT_FAILURE;
    }

    // Obter a operação a ser executada a partir da flag
    char op = argv[1][1];
    int n = atoi(argv[2]);

    // Executar a operação apropriada
    switch (op) {
        case 'f':
            // Fatorial
            if (argv[1][0] == 'r') {
                cout << fat.recursivo(n) << endl;
            } else {
                cout << fat.iterativo(n) << endl;
            }
            break;
        case 'b':
            // Fibonacci
            if (argv[1][0] == 'r') {
                cout << fib.recursivo(n) << endl;
            } else {
                cout << fib.iterativo(n) << endl;
            }
            break;
        default:
            cerr << "Erro: operação inválida." << endl;
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}