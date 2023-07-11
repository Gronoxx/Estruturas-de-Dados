#include <cmath>
#include <iostream>
#include <time.h>
#include <chrono>
#include <string>
void RandomVector(int vetorH[],int vetorS[],int size){
    int aux;
    srand(time(NULL));
    for(int i=0;i<size;i++){
        aux= rand() % 100;
        vetorH[i+1] = aux; 
        vetorS[i] = aux; 
    }
}


void Refaz(int Esq, int Dir, int *A){   
int i, j;
int x;
i = Esq;
j = i * 2;
x = A[i];
while (j <= Dir){
if (j < Dir)
if (A[j]< A[j+1]) j++;
if (x >= A[j]) break;
A[i] = A[j];
i = j;
j = i *2;
}
A[i] = x;
}
void Constroi(int *A, int n) {
int Esq;
Esq = n / 2 + 1;
while (Esq > 1) {
Esq--;
Refaz(Esq, n, A);
}
}
void shellSort(int *vet, int size) {
 int i, j, value;
 int h = 1;
 h = size - ceil(static_cast<double>(size) /4);
 while (h > 0) {    
 for(i = h; i < size; i++) {
 value = vet[i];
 j = i;
 while (j > h-1 && value <= vet[j - h]) {
 vet[j] = vet[j - h];
 j = j - h;
 }
 vet[j] = value;
 }
 h= floor(static_cast<double>(h) /2);
 }
}
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Argumentos faltando. <tamanho_vetor> <flag_para_tempo_total>"<< std::endl;
        std::cout << "-t: com tempo total"<< std::endl;
        std::cout << "-s: sem tempo total"<< std::endl;
        return 1;
    }
    std::string flag = argv[2];
    if(flag[0]!='s' && flag[0]!='t'){
        std::cout<<"Flag inválida"<<std::endl;
        return 1;
    }
    int size = std::stoi(argv[1]);
    int resultadoH[size+1];
    int resultadoS[size];
    RandomVector(resultadoH,resultadoS,size);
    auto inicio = std::chrono::high_resolution_clock::now();
    Constroi(resultadoH,size);
    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout<<std::endl;
    std::cout << "Tempo de execução HeapSort: " << duracao / 1e9 << " segundos" << std::endl;
    inicio = std::chrono::high_resolution_clock::now();
    shellSort(resultadoS,size);
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout<<std::endl;
    std::cout << "Tempo de execução ShellSort: " << duracao / 1e9 << " segundos" << std::endl;
    
    if(flag[0]=='s')
    return 0;
    else if(flag[0]=='t'){
    int resultadoH1[1000];
    int resultadoS1[1000];
    inicio = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<1000000;i++){
    RandomVector(resultadoH1,resultadoS1,100);
    Constroi(resultadoH1,100);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout << "Tempo de execução HeapSort 100: " << duracao / 1e9 << " segundos" << std::endl;
    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,100);
        shellSort(resultadoS1,100);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução ShellSort 100: " << duracao / 1e9 << " segundos" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,250);
        Constroi(resultadoH1,250);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução HeapSort 250: " << duracao / 1e9 << " segundos" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,250);
        shellSort(resultadoS1,250);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução ShellSort 250: " << duracao / 1e9 << " segundos" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,500);
        Constroi(resultadoH1,500);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução HeapSort 500: " << duracao / 1e9 << " segundos" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,500);
        shellSort(resultadoS1,500);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução ShellSort 500: " << duracao / 1e9 << " segundos" << std::endl;

     inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,1000);
        Constroi(resultadoH1,1000);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução HeapSort 1000: " << duracao / 1e9 << " segundos" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++){
        RandomVector(resultadoH1,resultadoS1,1000);
        shellSort(resultadoS1,1000);
    }
    fim = std::chrono::high_resolution_clock::now();
    duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio).count();
    std::cout << "Tempo de execução ShellSort 1000: " << duracao / 1e9 << " segundos" << std::endl;
    }
    return 0;
}