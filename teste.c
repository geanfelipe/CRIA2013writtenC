#include <stdio.h>


int main()
{
	int i=10,x=0;
	
	for(;;)
	{
		x++;
		if (x==10) printf("eita poha, iguazim a 10\n");
		else if(x==100)
		{
			printf("eita poha, iguazim a 100\n"); 
			break;
		}
		else printf("nadinha viss\n");
	}

	return 0;
}
