#ifndef NOMAPA_HPP
#define NOMAPA_HPP
#include <string>
class No_mapa {
    public:
    std::string chave;
    std::string valor;
    No_mapa* esquerda=nullptr;
    No_mapa* direita=nullptr;
    int height;

    No_mapa(std::string k, const std::string& v);
};
#endif
