#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct NO{
       int dado;
       struct NO *esquerda, *direita, *pai;
};
typedef struct NO ARVORE;
ARVORE *inicia_arvore(){
    return NULL;
}
ARVORE *arvore_insere(ARVORE *arvore, int v){
    ARVORE *auxiliar;
    
    if(arvore == NULL){
       auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
       auxiliar->dado = v;
       auxiliar->esquerda = inicia_arvore();
       auxiliar->direita = inicia_arvore();
       return auxiliar;
       }
    else{
         int dir;
         auxiliar = arvore;
         ARVORE *pai = NULL, *raiz = arvore;
         while(auxiliar != NULL){
           pai = auxiliar;
           if(v <= auxiliar->dado){
              dir = 0;
              auxiliar = auxiliar->esquerda;
              }
           else{
              dir = 1;
              auxiliar = auxiliar->direita;
              }
           }
    auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
    auxiliar->dado = v;
    auxiliar->esquerda = inicia_arvore();
    auxiliar->direita = inicia_arvore();
    
    if(dir)
      pai->direita = auxiliar;
    else
      pai->esquerda = auxiliar;
      return raiz;
    }
}
int vazia(ARVORE *a){
    return a == NULL;
}
void preOrdem(ARVORE *a){
    if(a != NULL){
    	printf("%d ", a->dado);
        preOrdem(a->esquerda);
        
        preOrdem(a->direita);
        
        
    }
}
void imprimir_arvore(ARVORE *a){
     printf("\n\n\t Pai %d \n",a->dado);
     if(a->esquerda != NULL){
     	printf("Esquerdo: %d\t",a->esquerda->dado);	
	 }       
     else{
     	printf("Esquerdo: NULL\t");
	 }
       
     if(a->direita != NULL){
     	printf("\tDireito: %d\t",a->direita->dado);
	 }       
     else{
     	printf("Direito: NULL\t");
	 }
       
     if(a->esquerda != NULL){
     	imprimir_arvore(a->esquerda);
	 }
      
     if(a->direita != NULL){
     	imprimir_arvore(a->direita);
	 }
       
}
main(){
    ARVORE *a = inicia_arvore();
    int opcao, valor;
    
   setlocale(LC_ALL, ""); 	
	
   a = arvore_insere(a, 2);
   a = arvore_insere(a, 1);
   a = arvore_insere(a, 0);
   a = arvore_insere(a, 6);
   a = arvore_insere(a, 5);
   a = arvore_insere(a, 2);
   a = arvore_insere(a, 8);
   a = arvore_insere(a, 1);
    do{
    	if(!vazia(a)){
    		printf("\t\t\tArvore Binaria\n");
        	
            imprimir_arvore(a);
            printf("\n========================================\n");
            printf("\nRA: 21065281-5");
            printf(" - Visitação pré-ordem: ");
            preOrdem(a);
		}                 
        
        printf("\n\n1- Inserir NO\n"
               "0-Sair....\n");
        scanf("%d",&opcao);
        switch(opcao){
          case 1:
               printf("informe um valor: ");
               scanf("%d",&valor);
               a = arvore_insere(a, valor);
          break;
          
          case 0: break;
          default: printf("opcao invalida\n");
        }
     system("cls");
    }while(opcao != 0);
}




