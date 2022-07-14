#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Variaveis
int i, destino, origem, vertices = 0;
float custo;
float *custos = NULL;

//Prototipa��o
void dijkstra(int vertices, int origem, int destino, float *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);

//fun��o principal

int main (int argc, char**argv){
  int opt = -1;
  do{
  menu_mostrar();
  scanf("%d", &opt);
    switch(opt){
      case 1:
      grafo_criar();
      break;
      case 2:
        if(vertices > 0){
          grafo_procurar();
        }
      break;
    }
   } while(opt !=0);
    return 0;
}

//Desenhar o menu na tabela
void menu_mostrar(void) {
  
  printf("Algoritmo de Dijkstra\n");
  printf("Opcoes:\n");
  printf("\t 1 - Adicionar um Grafo \n");
  printf("\t 2 - Procurar os menores caminnhos no grafo \n");
  printf("\t 3 - Sair do Progama \n");
}

void grafo_criar(void){
  do{
    printf("\n Inserir o numero de Vertices: ");
    scanf("%d" , &vertices);
    }while(vertices < 3);

   if(!custos){
     free(custos);
   }
  custos = (float*) malloc(sizeof(float)*vertices*vertices);
  if(custos == NULL){
    printf("Erro: Memeria Insuficiente");
    exit(-1); 
  }

  //preenchendo a matriz com -1
  for( i = 0; i <= vertices * vertices ; i++){
    custos[i] = -1;
  }

  do {
    system("cls");
    printf("Entre com as arestas:\n");
    do{
      printf("Origem (entre 1 e %d ou '0' para sair)", vertices);
      scanf("%d" , &origem);
    }while (origem < 0 || origem > vertices);
  if(origem){
    do{
      printf("Destino (entre 1 e %d, menos %d)" , vertices , origem);
      scanf("%d", &destino);
    } while (destino < 1 || destino > vertices || destino == origem);
    do{
      printf("Custo (positivo) do vertice %d para o vertice %d: ",origem, destino);
      scanf("%f", &custo);
    } while (custo < 0);
    custos[(origem-1) * vertices + destino -1]= custo;
  }
  }while(origem); 
}

void grafo_procurar(void){
  int i, j;
  system("cls");
  printf("Lista dos Menores caminhos do Grafo Dado: \n");
  for(i = 1; i<= vertices; i++){
    for(j = 1; j <= vertices; j++){
      dijkstra(vertices, i, j, custos);
    }
  }
}

void dijkstra(int vertices, int origem, int destino, float *custos){
  int i, v, cont =0;
  int *ant, *tmp;
  int *z;
  double min;
  double dist[vertices];

  ant = (int *) calloc (vertices, sizeof(int*));
  if(ant == NULL){
    printf("Erro: Memoria Insuficiente");
    exit(-1);
  }
  tmp = (int *) calloc (vertices, sizeof(int *));
  if(tmp == NULL){
  printf("Erro: Memoria Insuficiente");
  exit(-1);
}
z = (int *) calloc(vertices , sizeof(int *));
if (z == NULL){
  printf("Erro: Memoria Insuficiente");
  exit(-1);
}

for (i = 0; i < vertices; i++){
  if(custos[(origem -1) * vertices + i] != -1){
    ant[i] = origem -1;
    dist[i] = custos[(origem - 1) * vertices + i];
  }else {
    ant[i] = -1;
    dist[i] = HUGE_VAL;
  }
  z[i] = 0;
}

z[origem-1] = 1;
dist[origem-1] = 0;


do {
  min = HUGE_VAL;
  for (i=0; i<vertices; i++){
    if(!z[i]){
      if(dist[i] >=0 && dist[i] < min){
        min = dist[i]; v=i;
      }
    }
  }
  
  if(min != HUGE_VAL && v != destino -1){
    z[v] = 1;
    for(i=0; i<vertices; i++){
      if(!z[i]){
        if(custos[v*vertices+i] != -1 && dist[v] +
custos[v*vertices+i] < dist[i]){
          dist[i] = dist[v] + custos[v*vertices+i];
          ant[i] = v;
        }
      }
    }
  }
} while(v != destino -1 && min != HUGE_VAL);

printf("\t De %d para %d: \t", origem, destino);
if(min == HUGE_VAL){
  printf("Nao existe\n");
  printf("\tCusto\t- \n");
} else {
  i = destino;
  i = ant[i-1];
  while(i != -1){
    tmp[cont] = i + 1;
    cont ++;
    i= ant[i];
  }
  for( i = cont; i>0; i--){
    printf("%d -> ", tmp[i - 1]);
  }
  printf("%d", destino);
  printf("\n\tCusto: %.3lf\n", dist[destino-1]);
}
}

