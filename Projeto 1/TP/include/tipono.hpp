#ifndef TIPONO_HPP
#define TIPONO_HPP
#include <string>
class TipoNo
{
public:
TipoNo();
void Set_Item(std::string item);
private:
std::string item;
TipoNo *esq;
TipoNo *dir;
friend class ArvoreBinaria;
};
#endif