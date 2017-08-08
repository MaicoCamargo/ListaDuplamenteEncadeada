#include "bli.h"
#include<stdio.h>
#include<stdlib.h>

main()
{
	agenda *pAgenda;
	pAgenda = NULL;//ponteiro do tipo agenda
	int escolha=0,saida=0;//saber o que o usuario escolheu
	while(escolha!=6 && saida==0 )
	{
		
		printf("  \n         AGENDA TELEFONICA EM ~ C ~ \n  \n ");
		printf("      1 ADD CONTATO \n       2 	EDITAR CONTATO \n       3 EXCLUIR \n       4 VISUALIZAR AGENDA \n       5 VIZUALIZAR CONTATO \n       6  SAIR\n");
		int escolha;//saber qual opcao do menu foi escolhida
		printf("\nabrir opcao |>");
		fflush(stdin);
		scanf("%d",&escolha);
		system("cls");
		fflush(stdin);
		if (escolha==1)
		{
			
			fflush(stdin);
			pAgenda = inserecontatos(pAgenda);
			
		}
		
		
		else  if (escolha==2)
		{
			imprime(pAgenda);
			printf("QUE CONTATO DESEJA EDITAR:");
			char editado[30];//saber que contato quer editar
			gets(editado);
			fflush(stdin);
			editar(pAgenda,editado);
			fflush(stdin);
		}
		else if (escolha==3)
		{
			printf("EXCLUIR:");
			char exclui[30];
			fflush(stdin);
			gets(exclui);
			fflush(stdin);
			excluir(pAgenda,exclui);
		}
		else if (escolha==4)
		{
			printf("\n  imprimindo lista de contatos........\n");
			imprime(pAgenda);
		}
		else if (escolha==5)
		{
			imprime(pAgenda);
			printf("\n   QUE CONTATO DESEJA VISUALIZAR:\n");
			char pesquisa[30];
			fflush(stdin);
			gets(pesquisa);//saber que contato que se quer ter uma visao detalhada 
			fflush(stdin);
			visualizarContato(pAgenda,pesquisa);
		}
		else 
		{
			printf("obrigado por usar esse app\n");
			saida=1;
		}
		
	}
	free(pAgenda);
	system("pause");
}
