#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char nome[], sexo[], idade[], cpf[];



struct elemento{
	char perguntas[300];
	int pontos;

};

struct elemento questoes[] = {
	
	{ .perguntas = "Tem febre? ", .pontos = 5 },
	{.perguntas = "Tem dor de cabeça? ", .pontos = 1},
	{.perguntas = "Tem secreção nasal ou espirros? ", .pontos = 1},
	{.perguntas = "Tem dor/irritação na garganta? ", .pontos = 1},
	{.perguntas = "Tem tosse seca? ", .pontos = 3},
	{.perguntas = "Tem dificuldade respiratória? ", .pontos = 10},
	{.perguntas = "Tem dores no corpo? ", .pontos = 1},
	{.perguntas = "Tem diarréia? ", .pontos = 1},
	{.perguntas = "Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? ", .pontos = 10},
	{.perguntas = "Esteve em locais com grande aglomeração? ", .pontos = 3},
	
};

	

void questionario(){
	
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	char resposta[100];
	int i = 0;
	int soma;
	
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("triagemPaciente.txt", "a");
	
	if (arquivoTxt == NULL)
	{
		printf("ERRO AO CRIAR ARQUIVO.");
	}
	
	
	
	
	printf("Resonda as perguntas abaixo com S(sim) ou N(nao)\n");
	
	for(i = 0; i < 10; i++){
		printf("%s", questoes[i].perguntas);
		scanf("%c", &resposta);
		fflush(stdin);
		
		fprintf(arquivoTxt, "%s %c\n", questoes[i].perguntas, resposta);
		if(resposta == 'S' || resposta == 's'){
			soma = soma + questoes[i].pontos;
		}
		
		
		
	}

fprintf(arquivoTxt, "Pontuação total: %d", soma);

fclose(arquivoTxt);

if(soma >= 0 && soma < 10){
		printf("Seus sintomas sao leve e deve se encaminhar para a ala de Baixo risco\n");	
	}
	
		if(soma >= 10 && soma < 20){
		printf("Seus sintomas sao medianos e deve se encaminhar para a ala de Medio risco\n");	
	}
	
		if(soma >= 20){
		printf("Seus sintomas sao graves e deve se encaminhar para a ala de Alto risco\n");
	}
	
	printf("Precione ENTER para encerrar..");
}
	

void cadastro_paciente(){
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("triagemPaciente.txt", "a");
	
	if (arquivoTxt == NULL)
	{
		printf("ERRO AO CRIAR ARQUIVO.");
	}
	
	printf("Cadastro de paciente: \n");
	printf("Nome: ");
	scanf("%s", nome);
	fflush(stdin);
	
	printf("\nSexo M/F: ");
	scanf("%s", sexo);
	fflush(stdin);
	
	printf("\nIdade: ");
	scanf("%s", idade);
	fflush(stdin);
	
	printf("\nCPF: ");
	scanf("%s", cpf);		
	fflush(stdin);
	
	fprintf(arquivoTxt, "Nome: %s\nSexo: %s\nIdade: %s\nCPF: %s\n", nome, sexo, idade, cpf);
	fclose(arquivoTxt);
	getchar();
	
	questionario();

}


void menu() {
	
	setlocale(LC_ALL, "Portuguese");
	
	int menu;

	printf("          MENU               \n");
	printf(" 1 - Cadastro de Paciente\n");
	printf(" 0 - Sair \n");

	scanf("%i", &menu);
	fflush(stdin);
	system("CLS");
	
	switch(menu){
		case 1:
		cadastro_paciente();	
			
		break;
		case 0:
		  printf("\nFinalizando o programa...");
		break;
	}
}
	
int main(){	

	menu();
	
	return 0;
}
