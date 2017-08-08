#include<stdio.h>
#include<stdlib.h>
#include<String.h>

struct infocontato//informacoes basicas do contato
{
	char nome[20];
	char sobrenome[30];
	char apelido[20];
};

struct fone 
{
	char tipo[30];
	char numero[10];
	int dd;//codigo de area
};

struct endereco
{
	char email[50];
	char residencial[50];
	char trabalho[50];
};

struct agenda
{
	struct infocontato contato;
	struct fone numeroCel;
	struct endereco end;
	struct agenda *prox;
	struct agenda *ant;   
};
typedef struct agenda agenda;

agenda *inserecontatos(agenda *pAgendaFI)
{
	fflush(stdin);
	agenda *novapos;
	novapos = (agenda*) malloc (sizeof(agenda));
	
	printf("   vamos preencher os campos asseguir !\n");
printf("\nNOME:");
			fflush(stdin);
			gets(novapos->contato.nome);//pega nome
			fflush(stdin);

			printf("\nSOBRENOME:");
			fflush(stdin);		
			gets(novapos->contato.sobrenome);//saber o sobre nome do contato
			fflush(stdin);

			printf("\n\nDESEJA ADICIONAR UM APELIDO:\n 0 sim --- 1 nao\n >opcao:");
			int op;//saber a opcao do usuario;
			fflush(stdin);
			scanf("%d",&op);
			fflush(stdin);
			if(op==0)
			{
				
				printf("APELIDO:");
				fflush(stdin);
				gets(novapos->contato.apelido);
				fflush(stdin);
			}
			else 
			{
				printf("\n                         apelido nao adicionado\n");
			}

			printf("\nINSERIR CODIGO DE AREA:\n 0 sim -- 1 nao\n>>>");
			int op1;//saber o que o usuario escolheu
			fflush(stdin);
			scanf("%d",&op1);
			fflush(stdin);
			if(op1==0)
			{
				printf("DD (codigo de area):");
				fflush(stdin);
				scanf("%d",&novapos->numeroCel.dd);//saber o codigo de area do celular	
				fflush(stdin);
			}
			else
			{
				printf("\n\n                codigo de area nao adicionado !\n\n");
			}
			printf("\nNUMERO:");
			fflush(stdin);
			gets(novapos->numeroCel.numero);
			fflush(stdin);
			printf("\nTIPO (residencial,comercial,fixo...) :");
			
			fflush(stdin);
			gets(novapos->numeroCel.tipo);//tipo de numero de telefone adicionado
			printf("\nEMAIL:");
			fflush(stdin);
			gets(novapos->end.email);//o email do contato
			fflush(stdin);
			printf("\n     ** ENDERECO ** \n");
			printf("\nDESEJA ADICIONAR O ENDERECO RESIDENCIAL:\n 0 sim -- 1 nao\n>>>");
			int opResidencia;//saber se quer add residencia ou nao do contato
			fflush(stdin);
			scanf("%d",&opResidencia);
			fflush(stdin);
			if(opResidencia==0)
			{
				printf("ENDERECO RESIDENCIAL:");
				fflush(stdin);
				gets(novapos->end.residencial);	
				fflush(stdin);
			}
		    else 
		    {
		    	printf("\n\n                           endereco residencial nao adicionado\n\n");

		    }
		    printf("\nDESEJA ADICIONAR O ENDERECO DO TRABALHO DO CONTATO:\n 0 sim -- 1 nao\n>>>");
		    int opTrabalho;//variavel para saber se quer add o endereco de trabalho ou nao
			fflush(stdin);
			scanf("%d",&opTrabalho);
			fflush(stdin);
			if(opTrabalho ==0 )
		    {
		    	printf("\n ENDERECO DO TRABALHO:");
				fflush(stdin);
				gets(novapos->end.trabalho);//endereco do trabalho do contato	
		    	fflush(stdin);
			}
		    else 
		    {
		    	printf("\n\n                            endereco de trabalho nao adicionado\n\n");
		    	
		    }
	
		
		
				
		    novapos->prox = pAgendaFI;
		    novapos->ant = NULL;
		    if(pAgendaFI!=NULL)
		    {
		    	pAgendaFI->ant = novapos;
		    }
		    
			return novapos;
			
}

void imprime(agenda *pontAg)
{
	agenda *aux;
	printf("\n\n");
	for(aux=pontAg; aux!=NULL;aux=aux->prox)
	{
		
		printf("|------------------------------|\n ");
		printf("<NOME:: %s %s >\n",aux->contato.nome,aux->contato.sobrenome);

		printf("<NUMERO:: (%d) %s >\n",aux->numeroCel.dd,aux->numeroCel.numero);

		printf("|------------------------------|\n");
	}
	
}

void visualizarContato(agenda *pontAg,char pes[])
{
	
	int aux1;//apenas para printar que nao foi achado resultado na pesquisa
	agenda *aux;
	printf("\n\n");
	for(aux=pontAg; aux!=NULL;aux=aux->prox)
	{
	
		if(strcmp(pes,aux->contato.nome)==0)
		{
			printf("<NOME:: %s %s >\n",aux->contato.nome,aux->contato.sobrenome);
			printf("<APELIDO:: %s >\n",aux->contato.apelido);
			printf("<NUMERO:: (%d) %s >\n",aux->numeroCel.dd,aux->numeroCel.numero);
			printf("<TIPO:: %s >\n",aux->numeroCel.tipo);
			printf("<EMAIL:: %s >\n",aux->end.email);
			printf("<ENDERECO:: %s >\n",aux->end.residencial);
			printf("<ENDERECO TRABALHO:: %s >\n",aux->end.trabalho);
			aux1=1;//
		}
	}
	if(aux1!=1)
	{
		printf("\nnao foi encontrado contato com o nome pesquisado\n\n");
	}
}

void editar(agenda *pontAg,char edi[])
{
	int aux1;//para caso o contato que for digitado nao existir
	agenda *aux;//para percorrer o laco
	printf("\n\n");
	for(aux=pontAg; aux!=NULL;aux=aux->prox)
	{
		if(strcmp(edi,aux->contato.nome)==0)
		{
			printf("edite o nome:");
			gets(aux->contato.nome);
			aux1=1;
		}
	}
	if(aux1!=1)
	{
		printf("\nnao foi encontrado contato com o nome pesquisado\n\n");
	}
	
}

agenda *excluir(agenda *pontAg, char exclui[])
{
	
	if(pontAg==NULL)
	{
		printf("\nlista vazia\n");
		return pontAg;
	}
	agenda *aux=pontAg;
	
	while (aux !=NULL && strcmp(exclui,aux->contato.nome)!=0)//laco para verificar se a o nome que foi escolido para ser excluido
	{
		aux = aux->prox;
	}
	
	if(aux->ant != NULL && aux->prox !=NULL)//excluir do meio da lista
	{

		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant; 
	}
	
	else if (aux->prox ==NULL) //exclui o primeiro digitado pelo usuario
	{
		aux->ant->prox= NULL;	
		pontAg = aux->ant;	
	}
	else if(aux->ant==NULL && aux->prox!=NULL)//exclui o ultimo digitado pelo usuario
	{
		
		aux->prox->ant = NULL;
	//	pontAg = aux->prox;
		
	}
	
	free(aux);
	return pontAg;
}
