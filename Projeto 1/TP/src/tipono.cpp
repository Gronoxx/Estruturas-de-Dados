#include "../include/tipono.hpp"
TipoNo::TipoNo()
{
item = ""; 
esq =NULL;
dir = NULL;
}
void TipoNo::Set_Item(std::string item){
    this->item =item;
}