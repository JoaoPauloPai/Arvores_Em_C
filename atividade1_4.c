//Bibliotecas
# include <stdio.h>
# include <stdlib.h>
#include<locale.h>
//Constantes
#define tamanho 100
#define E 0
#define D 1
#define R -1
//Estruturas
typedef struct str_no{
	char dado;
	int esquerda ;
	int direita ;
	int pai;
};
//Vari�veis
struct str_no arvore[tamanho];
int lado;
int indice = 0;
int i;
int opt = -1;
char pai, no;
//Prototipac�o
void mensagemNome();
void arvoresBinarias();
void menuPrincipal();
void mostra_arvore();
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
//Fun��o Principal
int main(void){
	setlocale(LC_ALL,"Portuguese");
	int temp;
	do{
	    system("cls");
		mensagemNome();
		arvoresBinarias();
		mostra_arvore();
		menuPrincipal();
		scanf("%d",&opt);
		switch(opt){
			case 1:
				system("cls");
				mensagemNome();
				arvoresBinarias();
				printf("\n               DIGITE O VALOR DO PAI.");
				scanf("%c",&pai);
				scanf("%c",&pai);
				printf("\n               DIGITE O VALOR DO N�.");
				scanf("%c",&no);
				scanf("%c",&no);
				printf("\n               DIGITE O LADO DA SUB-�RVORE (E=%d/D=%d/R=%d): ",E,D,R);
				scanf("%d",&lado);
				temp = arvore_procura(pai);
				arvore_insere(temp, no, lado);
				break;
			case 2:
				system("cls");
				mensagemNome();
				arvoresBinarias();
				printf("\n              DIGITE O VALOR DO N�.");
				scanf("%c",&no);
				scanf("%c",&no);
				system("cls");
				mensagemNome();
				arvoresBinarias();
				temp = arvore_procura(no);
				printf("                N� %c\n          Filho Esuquerda : %c\n          Filho Direita   : %c\n\n          ", arvore[temp].dado, arvore[arvore[temp].esquerda].dado, arvore[arvore[temp].direita].dado);
				system("pause");
				break;
        }//Fim do switch	
	}while(opt != 0);
	return (0);	
}//Fim do comando Main
//Insere N�
void arvore_insere(int pai, char dado, int lado){
	switch (lado){
		case E:
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice ++;
			break;
		case D:
			arvore[pai].direita = indice;
			arvore[indice].dado = dado;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice ++;
	    	break;
		case R:
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice ++;
	    	break;	
	}
	
}
//Procura N�
int arvore_procura(char dado){
	if (indice != 0){
		for (i = 0; i<indice; i++){
			if (arvore[i].dado == dado){
				return (i);
			}
		}
	}
	else{
		return (0);
	}
}
//Mostra Arvore
void mostra_arvore(){
	
         printf("          +================================================+\n");
	for(i = 0; i < indice; i++){
		printf("            | %c ", arvore[i].dado);
}
         printf("\n          +================================================+\n");
}
//Mensagens do Sistema
   void mensagemNome(){
	    printf("          +================================================+\n");
	    printf("          |       ALUNO-JO�O PAULO GOMES DA SILVA          |\n");
	    printf("          |       RA-20012120-5                            |\n");
	    printf("          |       ENGENHARIA DE SOFTWARE                   |\n");
	    printf("          +================================================+\n");  
	 }
   void arvoresBinarias(){
    	printf("          +================================================+\n");
   	    printf("          |                �RVORES BIN�RIAS                |\n"); 
   	    printf("          +================================================+\n"); 
   }
   	 //Menu Principal
	void menuPrincipal(){
    	printf("          +================================================+\n");
	    printf("          |                                                |\n");
    	printf("          |       1 - INSERI N� NA �RVORE                  |\n");   
	   	printf("          |                                                |\n");    
       	printf("          |       2 - PESQUISAR N� NA �RVORE               |\n");
    	printf("          |                                                |\n");
       	printf("          |       0 -    SAIR DO SISTEMA.                  |\n");
       	printf("          |                                                |\n");
       	printf("          +================================================+\n");
       	printf("\n\n                    Entre com a op��o desejada! ");      
    } 
