#ifndef TIPONO_HPP
#define TIPONO_HPP
#include <string>
class No
{
public:
No(char letra,bool leaf);
No *esq=nullptr;
No *dir=nullptr;
int freq;
bool leaf;
char letra;
};
#endif