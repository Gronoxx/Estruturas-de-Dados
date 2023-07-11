#include "../include/tipocel.hpp"
TipoCel::TipoCel(Ponto i){
    item=i;
    ant =NULL;
}
void TipoCel::Set_Ant(TipoCel *x){
    ant = x;
}
TipoCel* TipoCel::Get_Ant(){
    return ant;
}
Ponto TipoCel::Get_Item(){
    return this->item;
}