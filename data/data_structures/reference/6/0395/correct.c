#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
int Top;

int main()
{
	int a[MAX];
	Top = -1;
	int c;
	
	do{
		scanf("%d",&c);
		int d;
		
		if(1 == c)   // »Î’ª
		{
			scanf("%d",&d);
			if(MAX-1 == Top)
			{
				printf("error ");
			}
			else
			{
				a[++Top] = d;
			}
		 } 
		else if(0 == c)  // ≥ˆ’ª
		{
			if(Top == -1)
			{
				printf("error ");
			}
			else 
			{
				printf("%d ",a[Top]);
				Top--;
			}
		 } 
	}while(c != -1);
	return 0;
}

