#include <stdio.h>
#include <ctype.h> /*converte de minúscula para maiúscula e vice-versa*/

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
	char caracter=' ';
	int ok, filaLetra, sala,numero_da_poltrona;

	iniciar();
	
	printf("Qual o numero da sala[1/2/3]: ");
	scanf("%d",&sala);

	printf("digite letra da fileira: ");
	scanf("%c",&caracter);

	printf("digite número da poltrona: ");
	scanf("%d",&numero_da_poltrona);

	filaLetra=letra_das_fileiras(caracter); //retorna o valor em int da posicao da letra inserida pelo usuário no vetor
	printf("posicao do char %c é %d\n",caracter ,filaLetra);

	/*ok=preencher(sala,filaLetra,numero_da_poltrona);		//retorna 1 se preencheu e 0 se nao nao prencheeu
	if (ok) printf ("\nDEU CERTO\n");
	printf(" %c = letraFileira\n ",caracter);*/
	

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
			return posicao_da_letra;
		}
	}
}

/*funcao para caso
 preencher return igual a 1 --> preenche a vaga
caso contrário
 nao preenche
*/
int preencher(int sala, int filaLetra, int numero_da_poltrona)
{
	int verificar_as_cadeiras_usadas=0;
	
	if(poltrona[sala][filaLetra][numero_da_poltrona]=='0'){
		poltrona[sala][filaLetra][numero_da_poltrona]=='1';
		return 1;
	}
	else{
		printf("****Lugar ocupado****\na procurar lugar mais próximo na mesma fileira...\n");
		for(int i=0;i<20;i++){
			if (poltrona[sala][filaLetra][i]=='0'){
				poltrona[sala][filaLetra][i]='1';
				return 1;														 //caso tenha preenchido retorna 1													// e sai do loop
			}else verificar_as_cadeiras_usadas++;
		}

		//se verificar_as_cadeiras_usadas igual a 20 entao todas as cadeiras foram usadas daquela fila
		if (verificar_as_cadeiras_usadas==20){
			return 0;
		}
	}
}
