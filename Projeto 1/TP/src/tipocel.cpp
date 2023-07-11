#include "../include/tipocel.hpp"
TipoCel::TipoCel(TipoNo* i){
    item=i;
    ant =NULL;
}
void TipoCel::Set_Ant(TipoCel *x){
    ant = x;
}
TipoCel* TipoCel::Get_Ant(){
    return ant;
}
TipoNo* TipoCel::Get_Item(){
    return item;
}