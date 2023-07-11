#ifndef TIPOCEL_HPP
#define TIPOCEL_HPP

#include "../include/tipono.hpp"
#include <string>
#include <iostream>

class TipoCel{
private:
    TipoNo* item;
    TipoCel * ant;
public:
   TipoCel(TipoNo* i);
   void Set_Ant(TipoCel *x);
   TipoCel* Get_Ant();
   TipoNo* Get_Item();
};
#endif