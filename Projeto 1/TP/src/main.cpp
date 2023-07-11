#include "../include/arvbin.hpp"
#include <fstream>
#include <sstream>

ArvoreBinaria arv_exp;

bool isOperator(char str) {
    char operators[] = {'+','-','*','/'};
    for (int i = 0; i < 5; i++) {
        if (str == operators[i]) {
            return true;
        }
    }
    return false;
}
//Basicamente utiliza ooo fato de a maior prioridade eh qnd so tem um parenteses aberto, retira o operador os espacos e os parenteses da ponta, o q for pra esquerda vai pra esquerda
// diretia pra direita recursivamente,
//Tirara raiz como publica em arvore e dar um jeit na chamada da função 
//conferir se pode haver retorno do no nas funcoes de inserir
//use o ler para verificar a validade e armzene aqui ou pense em uma forma de armazenar e conferir validade aqui
//DOCUMENTAÇÃO: -> QUANDO TIVER SÓ UM PARENTESES COLOCA COMO RAIZ
//-> FILHO A ESQUERDA EXPRESSAO A ESQUERDA DO OPERADOR
// -> FILHO A DIREITA EXPRESSAO A DIREITA DO OPERADOR PARA OS DOIS CASOS AJEITAR PARENTESES PQ A CADA OPERADOR TEM UM PARENTESES A ESQUERDA E UM A DIREITA
void armazenainfixa(std::string entrada, int t,TipoNo*p)
{
    int i=0;
    std::string aux ="",holder="";
    std::string a,b;
    int par_a=0,par_f=0;
    for (char c: entrada){
        aux+=c;
        i++;
        if(c=='('){
        par_a++;
        }
        else if(isOperator(c)){
            if((par_a-par_f)==1){
                switch(t){
                    case 0:
                    p=arv_exp.Insere(aux,p);
                    break;
                    case 1:
                    p=arv_exp.InsereE(aux,p);
                    break;
                    case 2:
                    p=arv_exp.InsereD(aux,p);
                    break;
                }
                //tira o operador o espaço e o primeiro parenteses e o espaço
                a= entrada.substr(2,i-4);
                //tira o espaço e o ultimo parenteses
                b= entrada.substr(i+1,entrada.size()-i-2);
                armazenainfixa((a),1,p);
                armazenainfixa((b),2,p);
            }
        }
        else if(c==')'){
            par_f++;
        }
        else if(isdigit(c) || c=='.'){
            holder+=c;
        }
        aux="";
    }
    // só ou número ou expressão incompleta na ponta
    if(par_a == 1 || par_f==1){
        switch(t){
                    case 0:
                    arv_exp.Insere(holder,p);
                    break;
                    case 1:
                    arv_exp.InsereE(holder,p);
                    break;
                    case 2:
                    arv_exp.InsereD(holder,p);
                    break;
                } 
    }
}
void armazenaposfixa(std::string entrada){
    //Cria uma pilha de nós e garante que todos os nós criados serão inseridos na arvore para depois serem deletados corretamente
    Pilha p;
    TipoNo* no_p =NULL;
    TipoNo *aux1=NULL,*aux2=NULL;
    std::string holder="";
    for(int i =0; i<entrada.size();i++){
        
        if(isdigit(entrada[i])){
        while(entrada[i]!=' '){
        holder += entrada[i];
        i++;    
        }
        no_p = new TipoNo();
        no_p->Set_Item(holder);
        p.Empilha(no_p);
        holder = "";
        }
        if(isOperator(entrada[i])){
            holder = entrada[i];
            aux2=p.Desempilha();
            aux1=p.Desempilha();
            no_p = new TipoNo();
            no_p->Set_Item(holder);
            holder="";
            arv_exp.ArvoreBinariaBasica(no_p,aux1,aux2);
            p.Empilha(no_p);
        }
}
}


void LER(std::string TIPOEXP,std::string EXP){
    if(EXP.size()>1000){
        std::string ERRO="ERRO: ";
        ERRO+=EXP;
        ERRO+=" NAO VALIDA - EXPRESSÃO MAIOR QUE 1000 CARACTERES";
        throw ERRO;
       }
    
    if(TIPOEXP == "INFIXA"){
       if (EXP[0] != '('){
        std::string ERRO="ERRO: ";
        ERRO+=EXP;
        ERRO+=" NAO VALIDA - PRIMEIRO ELEMENTO DA INFIXA NÃO É UM PARÊNTESES";
        throw ERRO;
       }
    // ponteiro que segue a string pode ser aumentado em 1 na memoria, poiS a string está arazenada em uma região contígua de memória
    char *ptr_geral = &EXP[0];
    int countponto=0,countpar_a=0,countpar_f=0,countnum=0,countoper=0;
    char *ptr_princ1 = NULL, *ptr_princ2 = NULL;     
    bool ptr1=true;
    while(*ptr_geral != '\0'){
        if(isdigit(*ptr_geral) ){            
            countnum++;
            if(ptr1){
                ptr_princ1=ptr_geral;
                ptr1=false;
            }
            else {
                ptr_princ2=ptr_geral;
                ptr1=true;
            }
            while (*ptr_geral != ' ')
            {
                if(*ptr_geral=='.')
                countponto++;
                else if(!isdigit(*ptr_geral)){
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - CARACTERE INTRUSO NO MEIO DE NÚMERO DECIMAL";
                 throw ERRO;
                }
                if(countponto>1){
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - NÚMERO DECIMAL COM MAIS DE UM PONTO";
                 throw ERRO;
                }
                ptr_geral++;
            }
            countponto=0; 
             if(ptr_princ1 !=NULL && ptr_princ2!=NULL){    
        if(isdigit(*ptr_princ1) && isdigit(*ptr_princ2)){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - DOIS NÚMEROS EM SEQUÊNCIA NA INFIXA";
            throw ERRO;
            }
        }    
        }
        else if(isOperator(*ptr_geral)){
            countoper++;
            if(ptr_princ1==NULL){
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - PRIMEIRO ELEMENTO É OPERADOR E NÃO NÚMERO NA INFIXA";
                 throw ERRO;
                }
                if(ptr_geral-2 == NULL)
                {
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - OPERADOR EM LUGAR INDEVIDO";
                 throw ERRO;
                }
            else if(*(ptr_geral-2)=='('){
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - OPERADOR IMEDIATAMENTE DEPOIS DE ABERTURA DE PARENTESES";
                 throw ERRO;
                }
                if(ptr1){
                ptr_princ1=ptr_geral;
                ptr1=false;
            }
            else {
                ptr_princ2=ptr_geral;
                ptr1=true;
            }
            if(ptr_princ1 !=NULL && ptr_princ2!=NULL){    
            if(isOperator(*ptr_princ1) && isOperator(*ptr_princ2)){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - DOIS OPERADORES EM SEQUÊNCIA NA INFIXA";
            throw ERRO;
            }
            }
        }
        else if(*ptr_geral =='(')
            countpar_a++;
        else if(*ptr_geral ==')'){
            countpar_f++;
            if(!isdigit(*(ptr_geral-2)) && (*(ptr_geral-2)) != ')'){
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - FECHAMENTO DE PARÊNTESES INDEVIDO";
                 throw ERRO;
                }
            if(ptr_geral-2 == NULL)
            {
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - FECHAMENTO DE PARÊNTESES INDEVIDO";
                 throw ERRO;
                }
            else if(isOperator(*(ptr_geral-2)))
            {
                 std::string ERRO="ERRO: ";
                 ERRO+=EXP;
                 ERRO+=" NAO VALIDA - FECHAMENTO DE PARÊNTESES IMEDIATAMENTE APÓS OPERADOR";
                 throw ERRO;
                }
        }
        else if(*ptr_geral ==' '){}
        else{
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - CARACTERE INVÁLIDO PARA INFIXA";
            throw ERRO;
        }
        ptr_geral++;
    }
    if(ptr1){
        if(isOperator(*ptr_princ2)){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - ÚLTIMO ELEMENTO DEVE SER UMA NÚMERO E NÃO OPERADOR NA INFIXA";
            throw ERRO;
            }
    }
    else{
       if(isOperator(*ptr_princ1)){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - ÚLTIMO ELEMENTO DEVE SER UM NÚMERO E NÃO OPERADOR NA INFIXA";
            throw ERRO;
            }
    }
    if(countpar_a!=countpar_f){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - NÚMERO DE PARÊNTESES ABERTOS E FECHADOS INVÁLIDO";
            throw ERRO;
            }
    if(countnum<2 || countoper<1){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - INSUFICIÊNCIA DE NÚMEROS(2) OU OPERADORES(1)";
            throw ERRO;
        }
        //temos que o primeiro operador gera 3 par_a
        // a seguir pooder realizar uma operação com um número ou com uma expressão
        // num -> +1 oper + 2 par_a
        // exp -> +2 oper + 4 par_a
        // ou seja teremos sempre o acréscimo do dobro de par que operadores, mas a primeira expressão gera o + 1
        if(((countoper*2)+1)!=countpar_a)
        {
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA";
            throw ERRO;
        }
    arv_exp.Limpa(); 
    armazenainfixa(EXP,0,arv_exp.Get_Raiz());
    std::cout<<"EXPRESSAO OK: "<<EXP<<std::endl;
    }
    else if(TIPOEXP=="POSFIXA"){
    if (!isdigit(EXP[0])){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - PRIMEIRO ELEMENTO DA POSFIXA NÃO É UM NÚMERO";
            throw ERRO;
            }
    char *ptr_geral = &EXP[0];
    int countnum=0,countoper=0,countponto=0;
    while(*ptr_geral != '\0'){     
        if(isdigit(*ptr_geral)){
        countnum++;
        while (*ptr_geral != ' ')
            {
                if(*ptr_geral=='.')
                countponto++;
                else if(!isdigit(*ptr_geral)){
                        std::string ERRO="ERRO: ";
                        ERRO+=EXP;
                        ERRO+=" NAO VALIDA - CARACTERE INTRUSO NO MEIO DE NÚMERO DECIMAL";
                         throw ERRO;
                        }  
                if(countponto>1){
                        std::string ERRO="ERRO: ";
                        ERRO+=EXP;
                        ERRO+=" NAO VALIDA - NÚMERO DECIMAL COM MAIS DE UM PONTO";
                         throw ERRO;
                        }
                if(*(ptr_geral+1) != '\0') 
                ptr_geral++;
                else
                break;
            }
            countponto=0;    
        }
        else if(isOperator(*ptr_geral))
            countoper++;
        else if(*ptr_geral==' '){}
        else{
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - CARACTERE INVÁLIDO PARA POSFIXA";
            throw ERRO;
            }
        if(*(ptr_geral+1)=='\0'){
        while(*ptr_geral == ' '){
            ptr_geral--;
        }
        if(!isOperator(*ptr_geral)){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - ULTIMO ELEMENTO DA POSFIXA DIFERENTE DE OPERADOR";
            throw ERRO;
            }
            break;
        } 
        ptr_geral++;
    }
    if(countnum<2 || countoper<1){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA -INSUFICIÊNCIA DE NÚMEROS(2) OU OPERADORES(1)";
            throw ERRO;
            }
    if(countnum-countoper!=1){
            std::string ERRO="ERRO: ";
            ERRO+=EXP;
            ERRO+=" NAO VALIDA - A DIFERENÇA ENTRE NÚMEROS E OPERADORES DA POSFIXA DEVE SER DE 1";
            throw ERRO;
            }
    arv_exp.Limpa(); 
    armazenaposfixa(EXP);
    std::cout<<"EXPRESSAO OK: "<<EXP<<std::endl;
}
else{
    throw "ERRO: PARAMETRO INVÁLIDO";
    }
arv_exp.Set_Tipo(TIPOEXP);
} 
void INFIXA(){
    if(arv_exp.Get_Raiz()==NULL)
    throw "ERRO: EXP NAO EXISTE";
    else{
        arv_exp.Set_Tipo("INFIXA");
        std::cout<<"INFIXA: ";
        arv_exp.Imprimir(arv_exp.Get_Raiz());
        std::cout<<std::endl;
    }
}
void POSFIXA(){
    if(arv_exp.Get_Raiz() ==NULL)
    throw "ERRO: EXP NAO EXISTE";
    else{
        arv_exp.Set_Tipo("POSFIXA");
        std::cout<<"POSFIXA: ";
        arv_exp.Imprimir(arv_exp.Get_Raiz());
        std::cout<<std::endl;
    }
}
void RESOLVE(){
    if(arv_exp.Get_Raiz() ==NULL)
    throw "ERRO: EXP NAO EXISTE";
    std::cout<<"VAL : "<<arv_exp.Resolve(arv_exp.Get_Raiz());
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Nome do arquivo não foi fornecido como argumento." << std::endl;
        return 1;
    }
    std::ifstream arquivo(argv[1]);
    if (!arquivo.is_open()) {
        std::cout << "Não foi possível abrir o arquivo " << argv[1] << std::endl;
        return 1;
    }
    if (arquivo.is_open()) {
        std::string linha;
        try{
        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string palavra;
            iss >> palavra;
            if(palavra == "LER"){
            std::string palavra2;
            iss >> palavra2;
            if(palavra2== "INFIXA" ||palavra2=="POSFIXA"){
                std::string exp;
                std::getline(iss >> std::ws, exp);
                LER(palavra2,exp);
            }
            else
            throw "ERRO: PARAMETRO DE LER INVALIDO";
            }
            else if(palavra =="INFIXA")
                INFIXA();
            else if(palavra == "POSFIXA")
                POSFIXA();
            else if(palavra == "RESOLVE")
                RESOLVE();
            else if(palavra == ""){
                //apenas evita erro por "enter"
            }
            else{
                throw "ERRO: COMANDO INVALIDO";
            }
        }
        }
        catch(const char * msg){
            std::cout<<msg<<std::endl;
            std::cout<<std::endl<<std::endl<<std::endl;
            return 1;
        }
        catch (std::string msg) {
        std::cout << msg << std::endl;
        std::cout<<std::endl<<std::endl<<std::endl;
        return 1;
        }
        arquivo.close();
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    return 0;

}