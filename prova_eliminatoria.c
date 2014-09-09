#include <stdio.h>
#include <ctype.h>

/*
São três salas idênticas com 360 lugares
*/

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
	int ok, posicao, sala,numero_da_poltrona;

	iniciar();
	
	printf("Qual o numero da sala[1,2,3]: ");
	scanf("%d",&sala);

	printf("digite número da poltrona: ");
	scanf("%d",&numero_da_poltrona);

	printf("digite letra da fileira: ");
	scanf("%c",&c);

/*posicao=letra_das_fileiras(c); //retorna o valor em int da posicao do char

	preencher(sala,posicao,numero_da_poltrona);
	ok=preencher(1,posicao,20);		//retorna 1 se preencheu e 0 se nao nao prencheeu
	if (ok==1) printf ("deu certo\n");
	else printf("n foi\n");

	printf("matriz %d\n",poltrona[sala][posicao][numero_da_poltrona]);*/
	

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
int preencher(int sala, int filaLetra, int numero_da_poltrona)
{
//	int poltronas_disponiveis[20];
	int verificar_as_cadeiras_usadas=0;
	
	if(poltrona[sala][filaLetra][numero_da_poltrona]=='0'){
		poltrona[sala][filaLetra][numero_da_poltrona]=='1';
		return 1;
	}
	else{
		printf("****Lugar ocupado****\na procurar lugar mais próximo na mesma fileira...\n");
		for(int i=0;i<20;i++){
			if (poltrona[sala][filaLetra][i]=='0'){
				poltrona[sala][filaLetra][i]=1;
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
