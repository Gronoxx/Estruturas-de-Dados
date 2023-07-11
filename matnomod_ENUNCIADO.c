//---------------------------------------------------------------------
// Arquivo	: matnomod.c
// Conteudo	: implementacao nao modularizada do TAD MAT 
// Autor	: Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico	: 2023-03-20 - arquivo criado
//---------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <getopt.h>

#define avisoAssert(e,m) ((void) ((e)?0: __avisoassert (#e,__FILE__,__LINE__,m)))
#define __avisoassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Aviso: '%s' - %s\n",file,line,e,m),0)
#define erroAssert(e,m) ((void) ((e)?0: __erroassert (#e,__FILE__,__LINE__,m)))
#define __erroassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Erro '%s' - %s\n",file,line,e,m), abort(),0)

#define MAXTAM 5

typedef struct mat{
	double m[MAXTAM][MAXTAM];
	int tamx, tamy;
	int id;
} mat_tipo;

// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10
// Macro que realiza swap sem variavel auxiliar
#define ELEMSWAP(x,y) (x+=y,y=x-y,x-=y)

void criaMatriz(mat_tipo * mat, int tx, int ty, int id)
// Descricao: cria matriz com dimensoes tx X ty
// Entrada: mat, tx, ty, id
// Saida: mat
{
  // verifica se os valores de tx e ty são validos
  erroAssert(tx>0,"Dimensao nula");
  erroAssert(ty>0,"Dimensao nula");
  erroAssert(tx<=MAXTAM,"Dimensao maior que permitido");
  erroAssert(ty<=MAXTAM,"Dimensao maior que permitido");

  // inicializa as dimensoes da matriz
  mat->tamx = tx;
  mat->tamy = ty;
  // inicializa o identificador da matriz, para rastreamento
  mat->id = id;
}

void inicializaMatrizNula(mat_tipo * mat)
// Descricao: inicializa mat com valores nulos 
// Entrada: mat
// Saida: mat
{
  int i, j;
  // inicializa todos os elementos da matriz com 0, por seguranca 
  for (i=0; i<MAXTAM; i++){
    for(j=0; j<MAXTAM; j++){
      mat->m[i][j] = 0;
    }
  }
}

void inicializaMatrizAleatoria(mat_tipo * mat)
// Descricao: inicializa mat com valores aleatorios
// Entrada: mat 
// Saida: mat
{
  int i, j;
  // inicializa a matriz com valores nulos, por seguranca
  inicializaMatrizNula(mat);
  // inicializa a parte alocada da matriz com valores aleatorios
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      mat->m[i][j] = drand48()*INITRANDOMRANGE;
    }
  }
}

double acessaMatriz(mat_tipo * mat)
// Descricao: acessa mat para fins de registro de acesso 
// Entrada: mat 
// Saida: mat
{
  int i, j;
  double aux, s=0.0;
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      aux = mat->m[i][j];
      s+=aux;
    }
  }
  return s; // apenas para evitar que acesso seja eliminado
}

void imprimeMatriz(mat_tipo * mat)
// Descricao: imprime a matriz com a identificacao de linhas e colunas
// Entrada: mat
// Saida: impressao na saida padrao (stdout) 
{
  int i,j;

  // seguranca, mas erro não deve acontecer jamais
  erroAssert(mat->tamx<=MAXTAM,"Dimensao maior que permitido");
  erroAssert(mat->tamy<=MAXTAM,"Dimensao maior que permitido");

  // imprime os identificadores de coluna
  printf("%9s"," ");
  for(j=0; j<mat->tamy; j++)
    printf("%8d ",j);
  printf("\n");

  // imprime as linhas
  for (i=0; i<mat->tamx; i++){
    printf("%8d ",i);
    for(j=0; j<mat->tamy; j++){
      printf("%8.2f ",mat->m[i][j]);
    }
    printf("\n");
  }
}

void salvaMatriz(mat_tipo * mat, FILE * out)
// Descricao: salva a matriz em arquivo
// Entrada: mat
// Saida: out
{
  int i,j;

  // seguranca, mas erro não deve acontecer jamais
  erroAssert(mat->tamx<=MAXTAM,"Dimensao maior que permitido");
  erroAssert(mat->tamy<=MAXTAM,"Dimensao maior que permitido");

  fprintf(out,"%d %d\n",mat->tamx,mat->tamy);
  // imprime as linhas
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      fprintf(out, "%.6f ",mat->m[i][j]);
    }
    fprintf(out,"\n");
  }
}

void escreveElemento(mat_tipo * mat, int x, int y, double v)
// Descricao: atribui o valor v ao elemento (x,y) de mat
// Entrada: mat, x, y, v
// Saida: mat
{
  // verifica se x e y sao validos
  erroAssert((x<0)||(x>=mat->tamx),"Indice invalido");
  erroAssert((y<0)||(y>=mat->tamy),"Indice invalido");

  mat->m[x][y] = v;
}

double leElemento (mat_tipo * mat, int x, int y)
// Descricao: retorna o elemento (x,y) de mat 
// Entrada: mat, x, y
// Saida: mat[x][y] 
{
  // verifica se x e y sao validos
  erroAssert((x<0)||(x>=mat->tamx),"Indice invalido");
  erroAssert((y<0)||(y>=mat->tamy),"Indice invalido");

  return mat->m[x][y];
}

void copiaMatriz(mat_tipo *src, mat_tipo * dst, int dst_id)
// Descricao: faz uma copia de src em dst
// Entrada: src, dst_id
// Saida: dst
{
  int i,j;

  // cria novamente a matriz dst para ajustar as suas dimensoes
  criaMatriz(dst,src->tamx, src->tamy,dst_id);
  // inicializa a matriz dst como nula
  inicializaMatrizNula(dst);
  // copia os elementos da matriz src
  for (i=0; i<src->tamx; i++){
    for(j=0; j<src->tamy; j++){
      dst->m[i][j] = src->m[i][j];
    }
  }
}

void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
// Descricao: soma as matrizes a e b e armazena o resultado em c
// Entrada: a, b
// Saida: c
{
  int i,j;
  // verifica se as dimensoes das matrizes a e b sao as mesmas
  erroAssert(a->tamx==b->tamx,"Dimensoes incompativeis");
  erroAssert(a->tamy==b->tamy,"Dimensoes incompativeis");

  // inicializa a matriz c garantindo a compatibilidade das dimensoes
  criaMatriz(c,a->tamx, a->tamy, c->id);
  inicializaMatrizNula(c);

  // faz a soma elemento a elemento
  for (i=0; i<a->tamx; i++){
    for(j=0; j<a->tamy; j++){
      c->m[i][j] = a->m[i][j]+b->m[i][j];
    }
  }
}

void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
// Descricao: multiplica as matrizes a e b e armazena o resultado em c
// Entrada: a,b
// Saida: c
{
  int i,j,k;
  // verifica a compatibilidade das dimensoes 
  erroAssert(a->tamy==b->tamx,"Dimensoes incompativeis");

  // cria e inicializa a matriz c
  criaMatriz(c,a->tamx, b->tamy,c->id);
  inicializaMatrizNula(c);

  // realiza a multiplicacao de matrizes
  for (i=0; i<c->tamx;i++){
    for (j=0; j<c->tamy;j++){
      for (k=0; k<a->tamy;k++){
        c->m[i][j] += a->m[i][k]*b->m[k][j];
      }
    }
  }
}

void transpoeMatriz(mat_tipo *a)
// Descricao: transpoe a matriz a
// Entrada: a
// Saida: a
{
  int i,j,dim;
  
  // determina a maior dimensao entre tamx e tamy
  dim = (a->tamx>a->tamy?a->tamx:a->tamy);

  // faz a transposicao como se a matriz fosse quadrada
  for (i=0; i<dim; i++){
    for(j=i+1; j<dim; j++){
      ELEMSWAP((a->m[i][j]),(a->m[j][i]));
    }
  }
  // inverte as dimensoes da matriz transposta
  ELEMSWAP(a->tamx,a->tamy);
}

void destroiMatriz(mat_tipo *a)
// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida: a
{
  // apenas um aviso se a matriz for destruida mais de uma vez
  avisoAssert(((a->tamx>0)&&(a->tamy>0)),"Matriz já foi destruida");

  // torna as dimensoes invalidas
  a->id = a->tamx = a->tamy = -1;
}

// definicoes de operacoes a serem testadas
#define OPSOMAR 1
#define OPMULTIPLICAR 2
#define OPTRANSPOR 3
#define OPCRIAR 4

// variaveis globais para opcoes
static int opescolhida;
char outnome[100];
int optx, opty;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"matop\n");
  fprintf(stderr,"\t-s \t(somar matrizes) \n");
  fprintf(stderr,"\t-m \t(multiplicar matrizes) \n");
  fprintf(stderr,"\t-t \t(transpor matriz)\n");
  fprintf(stderr,"\t-c <arq> \t(cria matriz e salva em arq)\n");
  fprintf(stderr,"\t-x <int>\t(primeira dimensao)\n");
  fprintf(stderr,"\t-y <int>\t(segunda dimensao)\n");
}


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opescolhida = -1;
     optx = -1;
     opty = -1;
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "smtc:p:x:y:lh")) != EOF){
       switch(c) {
         case 'm':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPMULTIPLICAR;
                  break;
         case 's':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPSOMAR;
                  break;
         case 't':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPTRANSPOR;
                  break;
         case 'c':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = OPCRIAR;
	          strcpy(outnome,optarg);
                  break;
         case 'x': 
	          optx = atoi(optarg);
		  break;
         case 'y': 
	          opty = atoi(optarg);
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verificacao da consistencia das opcoes
     erroAssert(opescolhida>0,"matop - necessario escolher operacao");
     erroAssert(optx>0,"matop - dimensao X da matriz tem que ser positiva");
     erroAssert(opty>0,"matop - dimensao Y da matriz tem que ser positiva");
     if (opescolhida==OPCRIAR){
       erroAssert(strlen(outnome)>0, "matop - nome de arquivo de saida tem que ser definido");
     }
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao de operacoes de matrizes 
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
  // ate 3 matrizes sao utilizadas, dependendo da operacao
  mat_tipo a, b, c;
  FILE * outfile;

  // avaliar linha de comando
  parse_args(argc,argv);

  // execucao dependente da operacao escolhida
  switch (opescolhida){
    case OPSOMAR:
         // cria matrizes a e b aleatorias, que sao somadas para a matriz c
	 // matriz c é impressa e todas as matrizes sao destruidas
         criaMatriz(&a,optx,opty,0);
         inicializaMatrizAleatoria(&a);
         criaMatriz(&b,optx,opty,1);
         inicializaMatrizAleatoria(&b);
         criaMatriz(&c,optx,opty,2);
         inicializaMatrizNula(&c);
         somaMatrizes(&a,&b,&c);
	 imprimeMatriz(&c);
         destroiMatriz(&a);
         destroiMatriz(&b);
         destroiMatriz(&c);
	 break;
    case OPMULTIPLICAR:
         // cria matrizes a e b aleatorias, que sao multiplicadas para matriz c
	 // matriz c é impressa e todas as matrizes sao destruidas
         criaMatriz(&a,optx,opty,0);
         inicializaMatrizAleatoria(&a);
         criaMatriz(&b,opty,optx,1);
         inicializaMatrizAleatoria(&b);
         criaMatriz(&c,optx,optx,2);
         inicializaMatrizNula(&c);
         multiplicaMatrizes(&a,&b,&c);
	 imprimeMatriz(&c);
         destroiMatriz(&a);
         destroiMatriz(&b);
         destroiMatriz(&c);
	 break;
    case OPTRANSPOR:
         // cria matriz a aleatoria, que e transposta, impressa e destruida
         criaMatriz(&a,optx,opty,0);
         inicializaMatrizAleatoria(&a);
	 transpoeMatriz(&a);
	 imprimeMatriz(&a);
         destroiMatriz(&a);
	 break;
    case OPCRIAR:
         // cria matriz a aleatoria, que e salva
	 outfile = fopen(outnome,"wt");
         erroAssert(outfile != NULL,"Erro na criacao do arquivo de saida");
         criaMatriz(&a,optx,opty,0);
         inicializaMatrizAleatoria(&a);
	 salvaMatriz(&a,outfile);
         destroiMatriz(&a);
	 fclose(outfile);
	 break;
   default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
         uso();
	 exit(1);
  }

  // conclui registro de acesso
  return 0;
}

