#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	switch(n)
	{
		case 1: puts("1"); break;
		case 2: 
			puts("1 2");
			puts("2 1");
			break;
		case 3:
			puts("1 2 3");
			puts("1 3 2");
			puts("2 1 3");
			puts("2 3 1");
			puts("3 1 2");
			puts("3 2 1");
			break;
		case 4:
			puts("1 2 3 4");
			puts("1 2 4 3");
			puts("1 3 2 4");
			puts("1 3 4 2");
			puts("1 4 2 3");
			puts("1 4 3 2");
			puts("2 1 3 4");
			puts("2 1 4 3");
			puts("2 3 1 4");
			puts("2 3 4 1");
			puts("2 4 1 3");
			puts("2 4 3 1");
			puts("3 1 2 4");
			puts("3 1 4 2");
			puts("3 2 1 4");
			puts("3 2 4 1");
			puts("3 4 1 2");
			puts("3 4 2 1");
			puts("4 1 2 3");
			puts("4 1 3 2");
			puts("4 2 1 3");
			puts("4 2 3 1");
			puts("4 3 1 2");
			puts("4 3 2 1");
			break;
		case 5:
			puts("1 2 3 4 5");
			puts("1 2 3 5 4");
			puts("1 2 4 3 5");
			puts("1 2 4 5 3");
			puts("1 2 5 3 4");
			puts("1 2 5 4 3");
			puts("1 3 2 4 5");
			puts("1 3 2 5 4");
			puts("1 3 4 2 5");
			puts("1 3 4 5 2");
			puts("1 3 5 2 4");
			puts("1 3 5 4 2");
			puts("1 4 2 3 5");
			puts("1 4 2 5 3");
			puts("1 4 3 2 5");
			puts("1 4 3 5 2");
			puts("1 4 5 2 3");
			puts("1 4 5 3 2");
			puts("1 5 2 3 4");
			puts("1 5 2 4 3");
			puts("1 5 3 2 4");
			puts("1 5 3 4 2");
			puts("1 5 4 2 3");
			puts("1 5 4 3 2");
			
			puts("2 1 3 4 5");
			puts("2 1 3 5 4");
			puts("2 1 4 3 5");
			puts("2 1 4 5 3");
			puts("2 1 5 3 4");
			puts("2 1 5 4 3");
			puts("2 3 1 4 5");
			puts("2 3 1 5 4");
			puts("2 3 4 1 5");
			puts("2 3 4 5 1");
			puts("2 3 5 1 4");
			puts("2 3 5 4 1");
			puts("2 4 1 3 5");
			puts("2 4 1 5 3");
			puts("2 4 3 1 5");
			puts("2 4 3 5 1");
			puts("2 4 5 1 3");
			puts("2 4 5 3 1");
			puts("2 5 1 3 4");
			puts("2 5 1 4 3");
			puts("2 5 3 1 4");
			puts("2 5 3 4 1");
			puts("2 5 4 1 3");
			puts("2 5 4 3 1");
			
			puts("3 1 2 4 5");
			puts("3 1 2 5 4");
			puts("3 1 4 2 5");
			puts("3 1 4 5 2");
			puts("3 1 5 2 4");
			puts("3 1 5 4 2");
			puts("3 2 1 4 5");
			puts("3 2 1 5 4");
			puts("3 2 4 1 5");
			puts("3 2 4 5 1");
			puts("3 2 5 1 4");
			puts("3 2 5 4 1");
			puts("3 4 1 2 5");
			puts("3 4 1 5 2");
			puts("3 4 2 1 5");
			puts("3 4 2 5 1");
			puts("3 4 5 1 2");
			puts("3 4 5 2 1");
			puts("3 5 1 2 4");
			puts("3 5 1 4 2");
			puts("3 5 2 1 4");
			puts("3 5 2 4 1");
			puts("3 5 4 1 2");
			puts("3 5 4 2 1");
			
			puts("4 1 2 3 5");
			puts("4 1 2 5 3");
			puts("4 1 3 2 5");
			puts("4 1 3 5 2");
			puts("4 1 5 2 3");
			puts("4 1 5 3 2");
			puts("4 2 1 3 5");
			puts("4 2 1 5 3");
			puts("4 2 3 1 5");
			puts("4 2 3 5 1");
			puts("4 2 5 1 3");
			puts("4 2 5 3 1");
			puts("4 3 1 2 5");
			puts("4 3 1 5 2");
			puts("4 3 2 1 5");
			puts("4 3 2 5 1");
			puts("4 3 5 1 2");
			puts("4 3 5 2 1");
			puts("4 5 1 2 3");
			puts("4 5 1 3 2");
			puts("4 5 2 1 3");
			puts("4 5 2 3 1");
			puts("4 5 3 1 2");
			puts("4 5 3 2 1");
			
			puts("5 1 2 3 4");
			puts("5 1 2 4 3");
			puts("5 1 3 2 4");
			puts("5 1 3 4 2");
			puts("5 1 4 2 3");
			puts("5 1 4 3 2");
			puts("5 2 1 3 4");
			puts("5 2 1 4 3");
			puts("5 2 3 1 4");
			puts("5 2 3 4 1");
			puts("5 2 4 1 3");
			puts("5 2 4 3 1");
			puts("5 3 1 2 4");
			puts("5 3 1 4 2");
			puts("5 3 2 1 4");
			puts("5 3 2 4 1");
			puts("5 3 4 1 2");
			puts("5 3 4 2 1");
			puts("5 4 1 2 3");
			puts("5 4 1 3 2");
			puts("5 4 2 1 3");
			puts("5 4 2 3 1");
			puts("5 4 3 1 2");
			puts("5 4 3 2 1");
	}
	
	return 0;
}
