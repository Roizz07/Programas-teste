#include <stdio.h>//biblioteca de comunicação com usuário
#include <stdlib.h>//biblioteca de locação de espaço em mmemória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()
{
	//inicio da criação de variáveis /strings
	char arquivo[40];
	char cpf[40];//char é a string que vai cuidar dos caracteres
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado");
	scanf("%s", cpf);//% se refere a receber algo, o "s" significa string
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file;//FILE é uma função já feita pelo sistema que cria um arquivo, esse de nome file
		file = fopen(arquivo, "w");//aqui diz doque o "file" é composto,o w quer dizer escrever.
			fprintf(file,cpf);//o "f" antes do print diz que sera feito no file. Salva o valor da file
				fclose(file);//fecha a pasta
	
	file = fopen(arquivo, "a");// "a" serve para atualizar um arquivo ja existente.
		fprintf(file,",");
			fclose(file);
	
	printf("Digite o nome a ser cadastado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
		fprintf(file,nome);
			fclose(file);
			
	file = fopen(arquivo, "a");// "a" serve para atualizar um arquivo ja existente.
		fprintf(file,",");
			fclose(file);
			
	printf("Digite o sobrenome a ser cadastado:");
	scanf("%s",sobrenome);	
	
	file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
			fclose(file);
			
	file = fopen(arquivo, "a");// "a" serve para atualizar um arquivo ja existente.
		fprintf(file,",");
			fclose(file);
			
	printf("Digite o cargo a ser cadastado:");
	scanf("%s",cargo);	
	
	file = fopen(arquivo,"a");
		fprintf(file,cargo);
			fclose(file);
			
	system("pause");		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");// como uma função não enxerga a outra é preciso colocar de novo e localidade.

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");// r é ler, read
	
	if(file==NULL)
	{
		printf("Não foi possível encontrar este CPF.\n  ");
	}
	
	while(fgets(conteudo,200,file) !=NULL)//gets é buscar
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário  a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("CPF não está no sistema.\n");
		system("pause");
	}
	
	
}

int main()//sempre que uma função for concluida ela deve voltar para a main
{
	int opcao=0;//variável que vai armazenar a escolha do usuario
	int loop=1;

	for(loop=1;loop=1;)//x(/loop) é o numero de repetições que o programa vai fazer, e ele vai iniciar em x=1, e vai continuar operando enquanto x=1, desse modo ele vai operar indeterminadamente, caso eu colocasse x=10;x++ no final ele so iria voltar ao inicio 10 vezes, oque não queremos
	{//a abertura e o fechamento das chaves indicam o inicio e o fim do loop.
	
		system ("cls");//vai limpar a tela  
	 
	 setlocale(LC_ALL, "Portuguese");//diz a linguagem e a categoria do texto, permitindo colocar acentos,por exemplo.

		printf(" ### Alunos Eletro 5A ###\n\n");// \n pula linhas
	     	printf("Escolha a opção desejada:\n\n");
	        	 printf("\t1 - Registrar nomes \n");//\T faz dar um espaço na exibição
            	printf("\t2 - Consultar nomes \n");
             	printf("\t3 - Excluir nomes \n");
             	printf("\t4 - Sair do sistema \n\n");
             	printf("opção:");
         	scanf("%d",&opcao);//sacnf vai fazer o programa esperar ate uma resposta do usuario, %d vai dar espaço para que digite e &opcao vai armazenar a resposta dele
    	system ("cls");//vai limpar a tela    	
		
		switch(opcao)
		{
			case 1:
				registro();
			break;//os : são como o inicio das chaves do switch, e o break como o final
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema.\n");
			return 0;//Retornar ao valor zero, quebrando tudo, fechando o sistema
			
			default:
				printf("você não escolheu uma opção válida, por favor escolha entre as opções 1,2 e 3\n");
				system("pause");
			break;	
		} 
	}
}

