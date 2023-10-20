#include <stdio.h>  //biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel pr cadastras os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	
	char cpf[40];
	char nome[50];
	char sobrenome[40];
	char arquivo[40];
	char cargo[40];
	
	//final da cria��o de vari�veis/string
	
	printf("Digite seu CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar o vlor das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o "a" atualiza o arquivo
	fprintf(file, "\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, ".\n\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");
		
	}
	
	printf("Essas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("%s", conteudo);
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0;// Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)// laco de repeticao
	{
	
	
		system("cls");// codigo para apagar
	
		setlocale(LC_ALL,"Portuguese_Brazil.1252");//Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf(" Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema!\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao);// armazenando as escolhas do usuario
	
	
		system("cls"); // responsavel por limpar a tela
	
		switch(opcao) // inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf ("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;	
		} // fim da sele��o
	}
}
	
	
	
	
	

