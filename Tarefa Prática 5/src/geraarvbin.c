#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm{
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geraexp\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(semente)\n");
  fprintf(stderr,"\t-n <num>\t(numero de nos)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}


void parse_args(int argc, char ** argv, prm_t * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     // valores padrao
     prm->nomesaida[0] = 0;
     prm->semente = 0;
     prm->numno = 3;
     prm->numlevel = 2;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF){
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // semente aleatoria
	          prm->semente = atoi(optarg);
		  srand48((long) prm->semente);
		  break;
         case 'n':
	          // numero de nos
	          prm->numno = atoi(optarg);
		  prm->numlevel = ((int) log2((double) prm->numno))+2;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verifica apenas o nome do arquivo de saida
     if (!prm->nomesaida[0]) {
       printf("Arquivo de saida nao definido.");
       exit(1);
     }
}
void Pre_ordem(TipoApontador * T, int* vec) {
  static int count =0;
  if ((*T) != NULL) {
    vec[count]=(*T)->Reg.Chave;
    count++;
    Pre_ordem(&(*T)->Esq,vec);
    Pre_ordem(&(*T)->Dir,vec);
  }
}
void In_ordem(TipoApontador * T, int *vec) {
  static int count =0;  
  if ((*T) != NULL) {
    In_ordem(&(*T)->Esq,vec);
    vec[count]=(*T)->Reg.Chave;
    count++;
    In_ordem(&(*T)->Dir,vec);
  }
}
void Pos_ordem(TipoApontador * T, int *vec) {  
  static int count =0;
  if ((*T) != NULL) {
    Pos_ordem(&(*T)->Esq,vec);
    Pos_ordem(&(*T)->Dir,vec);
    vec[count]=(*T)->Reg.Chave;
    count++;
  }
}

void dumpTree(TipoApontador * T, int level, prm_t * prm) {
  if ((*T) != NULL) {
    for(int i=0; i<level; i++) fprintf(prm->saida,"    ");
    fprintf(prm->saida," %3ld (%d)\n", (*T)->Reg.Chave,level);
    dumpTree(&(*T)->Esq,level+1,prm);
    dumpTree(&(*T)->Dir,level+1,prm);
  }
}

int createTree(TipoNo ** curr, int level, prm_t * prm){
  // create node
  (*curr) = (TipoNo*) malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48()>((8.0*(1<<level)*prm->treesize))/(((1<<prm->numlevel)*prm->numno))){
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize<prm->numno) createTree(&((*curr)->Esq),level+1,prm);
    if (prm->treesize<prm->numno) createTree(&((*curr)->Dir),level+1,prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}

void ancestral(int i, int j,int * vec_pre,int* vec_pos, int tamanho_vec){
  int pre_i=-1,pre_j=-1,pos_i=-1,pos_j=-1;
  for(int count =0; count<tamanho_vec;count ++){
    if(vec_pre[count]==i)
    pre_i=count;
    if(vec_pre[count]==j)
    pre_j=count;
    if(vec_pos[count]==i)
    pos_i=count;
    if(vec_pos[count]==j)
    pos_j=count;
  }
  if((pre_i<pre_j)&&(pos_i>pos_j))
  printf("%d e ancestral de %d\n",i,j);
  else
  printf("%d nao e ancestral de %d\n",i,j);
}

int main(int argc, char *argv[])
{
  TipoNo *root;
  prm_t prm;
  int i,j;
  parse_args(argc,argv,&prm);
  prm.saida = fopen(prm.nomesaida,"wt");
  prm.treesize = 0;
  int vec_pre[prm.numno],vec_in[prm.numno],vec_pos[prm.numno];
  createTree(&root,0,&prm);
  dumpTree(&root,0,&prm);
  Pre_ordem(&root,vec_pre);
  In_ordem(&root,vec_in);
  Pos_ordem(&root,vec_pos);
  for (int k=0; k<prm.treesize; k++){
    i = j = 0;
    while (i==j){
      i = (int) (drand48()*prm.treesize);
      j = (int) (drand48()*prm.treesize);
    }
    fprintf(prm.saida,"%d testando ancestral(%d,%d)\n",k,i,j);
    ancestral(i,j,vec_pre,vec_pos,prm.numno); 
  }
    
  fclose(prm.saida);
  return 0;
} 
