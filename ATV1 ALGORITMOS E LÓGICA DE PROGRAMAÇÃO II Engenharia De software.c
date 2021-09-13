#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op, voto, votoPrefeito[]={0, 0, 0}, votoVereador[]={0, 0, 0, 0};
	
	do{
		printf("1 - Votar\n2 - Apuração dos votos\n3 - Sair: ");
		scanf("%d", &op);
		
		//system("pause");
		system("cls");
		switch(op){
			case 1:
				printf("Prefeito\n");
				printf("11 - Prefeito Dr. Zureta \n22 - Prefeito Senhor Gomes\n44 - Voto Nulo\nVoto: ");
				scanf("%d", &voto);
				if(voto == 11){
					votoPrefeito[0]++;
					printf("\nVoto para 11 - Prefeito Dr. Zureta\n");
				}else if(voto == 22){
					votoPrefeito[1]++;
					printf("\nVoto para 22 - Prefeito Senhor Gomes\n");
				}else if(voto == 44){
					votoPrefeito[2]++;
					printf("\n44 - Voto Nulo\n");
				}else{
					printf("\nVoto invalidado\n");
				}
				system("pause");
				system("cls");
				printf("Vereador\n");
				printf("111 - Vereador Joao do Frete \n222 - Vereador Maria da Pamonha\n333 - Vereador Ze da Farmacia\n444 - Voto Nulo\nVoto: ");
				scanf("%d", &voto);
				if(voto == 111){
					votoVereador[0]++;
					printf("\nVoto para 111 - Vereador Joao do Frete\n");
				}else if(voto == 222){
					votoVereador[1]++;
					printf("\nVoto para 222 - Vereador Maria da Pamonha\n");
				}else if(voto == 333){
					votoVereador[2]++;
					printf("\n333 - Vereador Ze da Farmacia\n");
				}else if(voto == 444){
					printf("\n44 - Voto Nulo\n");
					votoVereador[3]++;
				}else{
					printf("\nVoto invalidado\n");
				}
				system("pause");
				system("cls");
				
			
			break;
			case 2:
				printf("Prefeito\n");
				printf("\n11 - Prefeito Dr. Zureta: %d\n",votoPrefeito[0]);
				printf("\n22 - Prefeito Senhor Gomes: %d\n",votoPrefeito[1]);
				printf("\n44 - Voto Nulo: %d\n",votoPrefeito[2]);
				printf("\n--------------------------------------------------------\n");
				printf("Vereador\n");
				printf("\n111 - Vereador Joao do Frete: %d\n",votoVereador[0]);
				printf("\n222 - Vereador Maria da Pamonha: %d\n",votoVereador[1]);
				printf("\n333 - Vereador Ze da Farmacia: %d\n",votoVereador[2]);
				printf("\n444 - Voto Nulo: %d\n",votoVereador[3]);
				system("pause");
				system("cls");
			break;
			case 3:
				printf("\nPrograma Finalizado\n");
			break;
			default:
				printf("\nOpção Inválida\n");
		}
	
		
	}while(op != 3);
	
	
	return (0);

}
