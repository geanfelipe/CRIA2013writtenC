#include <stdio.h>
#include <ctype.h>


void letra_das_fileiras(char);
void iniciar();

char poltrona[3][21][20];

int main()
{
	int pos;
	char vetor[20]="Um texto em C";

	//se o vetor nao for ser modificado pode ser declarado
	char vetor1[] = "este é um vetor constante";
	char c;

	int vet[10];
	int x=0;	
	int y;

	vet[3]=3;
	vet[7]=5;
	vet[9]=10;

/*	for(int i=0; i<20;i++) printf("%c", vetor[i]);
	printf("\n");
	printf("%s\n", vetor1);
	
	printf("print the position ?");
	scanf("%d", &pos);
	printf("the position %d is %c\n", pos, matrizFileira[pos]); 
	printf("defina caracter: ");
	scanf("%c", &c);
	c= toupper(c);
	printf("%c\n", c);
	letra_das_fileiras(c);*/

	for(int i=0;i<20;i++){
			if (vet[i]=='0'){
				printf("lugar vazio encontrado posicao %d\n", i);
				vet[i] = i;
				y = vet[i];
				x+=1;
				if (x==1) x=0; printf("iuyy \n"); break;
			}
		}
	printf("preenchido com %d\n", y);

	return 0;
}

void iniciar()
{
	for(int x=0;x<3;x++){
		for(int i=0; i<21;i++){
			for(int j=0; j<20; j++){
				poltrona[x][i][j]='0';
			}
		}
	}
}

void letra_das_fileiras(char letra_da_fileira)
{
int posicao_da_letra =0 ;
char matrizFileira[]="ABCDEFGHIJKLMNOPQRSTU";

	for(int i=0;i<21;i++){
		if (matrizFileira[i]==letra_da_fileira){
			posicao_da_letra=i;
			printf("a posicao é %d ",posicao_da_letra);
		}
	}
	if (posicao_da_letra ==0){printf("caracter inválido\n");}
	
}
