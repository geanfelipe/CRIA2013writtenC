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


/*********************************OBSERVAÇAO***************************************/
/*se trocar a ordem de leitura de entrada do usuário dá bug na leitura da variável*/
/* 												     de nome caracter																		*/
/**********************************************************************************/
int main()
{
	char caracter;
	int ok, filaLetra, sala,numero_da_poltrona,opcao=1;
	

	iniciar();

	printf("\n                                   Seja Bem Vindo\n");
	printf("#");
	printf("\n|Salas existentes -> 1 a 3|\n|Letras das fileiras existentes -> A a U|\n|Número de poltronas existentes -> Fileira A até E: 1 a 8 de F até U: 1 a 20|\n");
	printf("#\n");
	printf("Opções de Navegação\n");

	while (1)   //loop principal do programa
	{
		printf("\n0) Sair\n");
		printf("1) Efetuar compra\n");

		while(1)  //loop das opcoes
		{
			printf(": ");
			scanf("%d",&opcao);
			if(opcao<3) break;
		}

		if (opcao==0) break;

		if (opcao==1)
		{
			while (1)
			{
				printf("\ndigite letra da fileira[A..U]: ");
				scanf("%c",&caracter);
		
				filaLetra=letra_das_fileiras(caracter); //retorna o valor em int da posicao da letra inserida pelo usuário no vetor	
				if (filaLetra<21) break;
			}

			while(1)
			{
				printf("qual o numero da sala[1/2/3]: ");
				scanf("%d",&sala);
				if ((sala ==1) | (sala==2) | (sala==3)) break;
			}															

			while(1)
			{
				if(filaLetra<6)
				{
					while(1)
					{
						printf("digite número da poltrona: ");
						scanf("%d",&numero_da_poltrona);
						if((numero_da_poltrona<9) & (numero_da_poltrona>0) & (numero_da_poltrona<21)) break;
						printf("#fileiras de A a E, as poltronas existentes são de 1 a 8\n");
					}
					break;
				}
				else
				{
					while(1)
					{
						printf("digite número da poltrona: ");
						scanf("%d",&numero_da_poltrona);
						if((numero_da_poltrona>0) & (numero_da_poltrona<21)) break;
					}
				}
			}

			numero_da_poltrona=numero_da_poltrona-1;						//posicao é de 0 a 19
			sala = sala - 1;																		//posicao é de 0 a 2
			printf("numero da poltrona escolhida foi %d\nfileira escolhida foi %d letra %c \n numero da sala %d\n", numero_da_poltrona, filaLetra, caracter, sala);
			ok=preencher(sala,filaLetra,numero_da_poltrona);		//retorna 1 se preencheu e 0 se nao nao prencheeu
			if (ok) printf ("\nCompra efetuada,Obrigado!\n");
		}
		
	}

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
/*existe um bug em relação ao retorno 0 pois se a letra nao for encontrada é retornado 0 e também é retornado esse mesmo valor se a letra a procurar for 'A' . Por isso inicia-se posicao_da_letra igual a 100(podia ser qualquer valor acima de 20) assim , na funcao main() se compara se o retorno da funcao é maior que 20(pois comeca em 0, indo até 20) podendo-se deduzir se foi a letra existe ou nao*/

int posicao_da_letra=100;

	caracterVerificacao = toupper(caracterVerificacao);   //caso o char for minusculo , o toupper põe em maiuscula

	for(int i=0;i<21;i++){
		if (matrizFileira[i]==caracterVerificacao){
			posicao_da_letra=i;
			return posicao_da_letra;
		}
	}

	return posicao_da_letra;
}

/*funcao para caso preencher return igual a 1 --> preenche a vaga caso contrário nao preenche */
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
