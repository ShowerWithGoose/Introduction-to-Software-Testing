#include "stdio.h"

int main(){
	int a,b,c,i=0,j,k;
	int A[100];
	scanf ("%d",&a);
	while (1)
	{
		if(a == 1)
	{
		if(i>=99)
		{
			printf ("error ");	
		}
		else
		{
			scanf ("%d",&A[i]);
			i++;
		}
	}
	else if (a == 0)
	{
		if(i<=0)
		{
			printf ("error ");			
		}
		else
		{
			i--;
			printf ("%d ",A[i]);
		}
	}
	else if(a == -1)
		break;
		
	scanf ("%d",&a);
	}
	
	
	return 0;
}

