#include <stdio.h>

int procure(int);

int main()
{
	int c,y,x;
	printf("qual o numero? ");
	scanf("%d",&c);
	y=procure(c);

	if (y) printf("eita poha,iguazim a %d\n ",c);
	else printf("eita poha,nem parece com %d\n",c);
	
	printf("y = %d\n",y);

	return 0;
}

int procure(int x)
{
	for (int i=0;i<10;i++){
		printf("--%d\n",i);
		if (x == i){
			return 1+1;
		}
	}
	
}