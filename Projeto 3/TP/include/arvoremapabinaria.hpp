#ifndef ARVORE_MAPA_BINARIA_HPP
#define ARVORE_MAPA_BINARIA_HPP
#include <iostream>
#include <string>
#include "mapano.hpp"
#include <fstream>

class ArvoreMapaBinaria {
public:
    ArvoreMapaBinaria();
    ~ArvoreMapaBinaria();

    void inserir(std::string chave, const std::string& valor);
    bool contem(std::string chave);
    void limpar();
    No_mapa * Get_raiz();
    std::string Encontrar_Valor(std::string chave);
private:
    No_mapa* raiz;

    No_mapa* inserirNo(No_mapa* no, std::string chave, const std::string& valor);
    No_mapa* encontrarNo(No_mapa* no, std::string chave);
    No_mapa* encontrarMinimo(No_mapa* no);
    void limparArvore(No_mapa* no);
};

#endif  // ARVORE_MAPA_BINARIA_HPP
