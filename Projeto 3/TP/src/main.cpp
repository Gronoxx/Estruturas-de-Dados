#include <iostream>
#include "../include/MinPriorityQueue.hpp"
#include <string>
#include "../include/arvoreh.hpp"
#include "../include/arvoremapabinaria.hpp"
#include "../include/mapano.hpp"
#include <fstream>
#include <sstream>
#include <cmath>
#include <cctype>
#include <bitset>

using namespace std;

ArvoreMapaBinaria binmap;

int stringTodecimal(string a){
    int resultado=0;
    int size =a.size();
    for(int i=0;i<size;i++){
        resultado+=(int(a[i])-48)*pow(10,size-i-1);
    }
    return resultado;
}

void Cod_Huffman(No* raiz, const std::string& code) {
    if (raiz == nullptr) {
        return;
    }
    if(raiz->leaf){
    string aux="";
    aux+=raiz->letra;
    binmap.inserir(aux,code);
    }

    Cod_Huffman(raiz->esq, code + "0");
    Cod_Huffman(raiz->dir, code + "1");
}


No * Huffman(MinPriorityQueue Q,bool cod){
    while(1<Q.Get_size()){
            No* aux1=Q.removeMin();
            No* aux2=Q.removeMin();
            int z_freq = aux1->freq +aux2->freq;
            No* z = new No('\0', false);
            z->freq = z_freq;
            z->esq=aux1;
            z->dir=aux2;
            Q.insert(z);
    }
    No* raiz = Q.removeMin();
    if(cod==true)
    Cod_Huffman(raiz,"");
    return raiz;
}

std::string lerArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << arquivo.rdbuf(); // Lê todo o conteúdo do arquivo e armazena no stringstream

    arquivo.close();

    return buffer.str(); // Retorna o conteúdo do stringstream como uma string
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Uso: programa <flag> <arquivo1> <arquivo2>" << std::endl;
        return 1;
    }

    string flag = argv[1];
    string nomeArquivo1 = argv[2];
    string nomeArquivo2 = argv[3];



    if(flag =="-c"){
    int aux[128]={};
    ofstream arquivoescrita(nomeArquivo2);
    string leitura =  lerArquivo(nomeArquivo1);
    int n= leitura.size();
    

    //Verificando as letras presentes
    for (int i =0;i<n;i++){
        aux[(leitura[i])]++;
    }
    MinPriorityQueue pq,pq2;
    //Criando os nós e empilhando
    int count=0;
    bool last_jump=false;
    if(arquivoescrita.is_open()){
    arquivoescrita<<n<<endl;
    for (int i =0;i<128;i++){
        if(aux[i]!=0){
        No * p =new No(i,true);
        p->freq=aux[i];
        No * aux1 =new No(i,true);
        aux1->freq=aux[i];
        pq.insert(p);
// Escrita
        if(0<=int(aux1->letra) && int(aux1->letra)<=32){
        if(count!=0 && last_jump==false)
        arquivoescrita<<endl;
        if(0<=int(aux1->letra) && int(aux1->letra)<=9)   
        arquivoescrita<<"0"<<int(aux1->letra)<<" "<<aux1->freq<<endl;
        else
        arquivoescrita<<int(aux1->letra)<<" "<<aux1->freq<<endl;
        last_jump=true;
        }
        else if(isdigit(aux1->letra)){
        if(count==0)
        arquivoescrita<<aux1->letra<<aux1->freq;
        else
        arquivoescrita<<endl<<aux1->letra<<aux1->freq; 
        }else
        arquivoescrita<<aux1->letra<<aux1->freq;
        count++;
        }
    }
    }
    Arvore arv(Huffman(pq,true));
    if (arquivoescrita.is_open()) { // Verifica se o arquivoescrita foi aberto com sucesso
        arquivoescrita<<endl<<endl;
        string aux="";
        string saida="";
        for(int i=0;i<n;i++){
            aux+=leitura[i];
            saida+=binmap.Encontrar_Valor(aux);
            aux="";
        }
        //temos saida com todos os binario
        int size = saida.size();
        for(int i=0;i<size;i+=8){
            char byte =0;
            for(int j=0;j<8;j++){
                if(i+j<size){
                    byte <<=1;
                    byte |= saida[i+j] - '0';
                }
                else{
                    byte<<=1;
                }
            }
            arquivoescrita<<byte;
        }
        arquivoescrita.close(); // Fecha o arquivo
   }else {
       cout << "Erro ao abrir o arquivo para escrita." << endl;
   }
    }


    else if(flag=="-d"){
        string linha;
        ifstream arquivoleitura(nomeArquivo1);
        ofstream arquivoescrita(nomeArquivo2);
        MinPriorityQueue pq;
        string aux="";
        if(arquivoescrita.is_open() && arquivoleitura.is_open()){
        std::getline(arquivoleitura, linha);
        int n=stringTodecimal(linha);
        while (std::getline(arquivoleitura, linha)) {
        // Check if the line is empty
        if (linha.empty()) {
            // proxima linha será a de binário
            Arvore arv(Huffman(pq,false));
            std::getline(arquivoleitura, linha);
            if(linha.empty()){
            std::getline(arquivoleitura, linha);
            }
            string linha2="";
            while (std::getline(arquivoleitura, linha2)) {
                linha+='\n';
                linha+=linha2;
            }
            string bitstring="";
            int size=linha.size();
            for(int i=0;i<linha.size();i++){
                bitstring+=bitset<8>(linha[i]).to_string();
            }
            No * auxilar=arv.Get_raiz();
            int count1=0;
            for(int i=0;i<bitstring.size();i++){
                if(auxilar->leaf==true){
                    arquivoescrita<<auxilar->letra;
                    auxilar=arv.Get_raiz();
                    count1++;
                    if(count1==n)
                    break;
                }
                if(bitstring[i]=='1'){
                    auxilar=auxilar->dir;
                }
                else if(bitstring[i]=='0'){
                    auxilar=auxilar->esq;
                }
                else{
                    std::cout<<"ERRO: Binário inválido";
                    return -1;
                }
            }
            break;
        }
        int size = linha.size();
        if(isdigit(linha[0])){
            if(linha[2]==' '){
            //0 a 32
            aux+=linha[0];
            aux+=linha[1];
            int indice=stringTodecimal(aux);
            char letra= indice;
            aux="";
            for(int i=3;i<size;i++){
                aux+=linha[i];
            }
            No* p =new No(letra,true);
            p->freq=stringTodecimal(aux);
            pq.insert(p);
            aux="";
            }
            else{
            //digit
            for(int i=0;i<size;i++){
            char letra = linha[i];
            while(isdigit(linha[i+1])){
                aux+=linha[i+1];
                i++;
            }
            No* p =new No(letra,true);
            p->freq=stringTodecimal(aux);
            pq.insert(p);
            aux="";
            }
            }
        }
        else{
            for(int i=0;i<size;i++){
            char letra = linha[i];
            while(isdigit(linha[i+1])){
                aux+=linha[i+1];
                i++;
            }
            No* p =new No(letra,true);
            p->freq=stringTodecimal(aux);
            pq.insert(p);
            aux="";
            }
        }
        
        }
        arquivoleitura.close();
        arquivoescrita.close();
    }
    else{
        std::cout<<"Erro ao abrir arquivos";
        return -1;
    }
    }
       
    return 0;
}