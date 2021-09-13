#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int qtd_cartelas, numero, bandeira, cartelaBingo[10], i, j, k, l;
	
	bandeira = 0;
	
	printf("digite quantas cartelas deseja obter\n");
	scanf("%i", &qtd_cartelas);
	fflush(stdin);
	srand ( time(NULL) );
	
	for(i = 0; i < qtd_cartelas; i++){
		
		for(j = 0; j < 10; j++){
			numero = (rand() % 99);
			
			for(k = 0; k <= j - 1; k++){
				if(numero == cartelaBingo[k]){
					bandeira = 1;
					break;
				}
			}
				
			if(bandeira ==1){
				bandeira = 0;
				j = j - 1;
			}else{
			
			cartelaBingo[j] = numero;		
			}		
		}
		printf("cartela %d:  ", i +1);
		for(l = 0; l < 10; l++){
			printf("%d ", cartelaBingo[l]);
		}
		printf("\n");
		
	}
}













