#ifndef TIPOCEL_HPP
#define TIPOCEL_HPP

#include <string>
#include <iostream>
#include "ponto.hpp"
class TipoCel{
private:
    Ponto item;
    TipoCel * ant;
public:
   TipoCel(Ponto  i);
   void Set_Ant(TipoCel *x);
   TipoCel* Get_Ant();
   Ponto Get_Item();
};
#endif