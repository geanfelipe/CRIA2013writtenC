#include <stdio.h>
#include <ctype.h>

/*
São três salas idênticas com 360 lugares
*/

int filaLetra;
int sala;
char letra_da_fileira;
int numero_da_poltrona;
char poltrona[3][21][20];
char matrizFileira[]="ABCDEFGHIJKLMNOPQRSTU";
char matrizFileiraInvalida[]="VXYZ";

/*declarando as funcoes*/
int letra_das_fileiras(char);
void iniciar();
int preencher(int, int, int);


int main()
{
	char c;
	int ok;
	int q;
	iniciar();
	printf("digite letra da fileira: ");
	scanf("%c",&c);
	filaLetra=letra_das_fileiras(c);
	preencher(1,filaLetra,20);
	q=preencher(1,filaLetra,20);
	if (q==1) printf ("\ndeu certo\n");
	else printf("n foi\n");
	
/*	if(filaLetra){
		ok=preencher(1, filaLetra, 21);
		if (ok) printf("****Vaga comprada com sucesso!****\n");
		else printf("****Vagas ocupadas****\n");
	}
	else printf("posicao nao existe\n");*/

	return 0;
}

//inicialização da matriz com todas as posições igual a 0
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

//retorna em int a posicao da letra na fila
int letra_das_fileiras(char caracterVerificacao)
{
int posicao_da_letra=0;
//caso o char for minusculo , o toupper põe em maiuscula
caracterVerificacao = toupper(caracterVerificacao);

	for(int i=0;i<21;i++){
		if (matrizFileira[i]==caracterVerificacao){
			posicao_da_letra=i;
			return posicao_da_letra+1;
			break;
		}
	}
}

//funcao p preencher caso return ==1 --> preenchido senao nao preenchido 
int preencher(int sl, int filaD, int np)
{
//	int poltronas_disponiveis[20];
	int verificar_as_cadeiras_usadas=0;
	
	if(poltrona[sl][filaD][np]=='0'){
		poltrona[sl][filaD][np]=='1';
		return 1;
	}
	else{
		printf("****Lugar ocupado****\na procurar lugar mais próximo na mesma fileira...\n");
		for(int i=0;i<20;i++){
			if (poltrona[sl][filaD][i]=='0'){
				poltrona[sl][filaD][i]=1;
				return 1;
			  break;
			}else verificar_as_cadeiras_usadas++;
		}

		//se var verificar_as_cadeiras_usadas == 20 entao todas as cadeiras foram usadas daquela fila
		if (verificar_as_cadeiras_usadas==20){
			return 0;
		}
	}
}
