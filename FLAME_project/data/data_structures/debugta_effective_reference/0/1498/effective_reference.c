#include "stdio.h"
#include "string.h"

int main(){
	char A[200],B[200];
	int i,j,k,l,a;
	gets(A);
	for (i=0;A[i]!='\0';i++)
	{
		if (A[i]=='-')
		{
			if ((A[i-1]>='a'&&A[i-1]<='z')&&(A[i+1]>='a'&&A[i+1]<='z')) 
			{
				if(A[i-1]<A[i+1]) 
				{
					for (j=1;j<=A[i+1]-A[i-1];j++)
					{
						printf ("%c",A[i-1]+j);
					}
					i++;
				}
			}
			else if ((A[i-1]>='A'&&A[i-1]<='Z')&&(A[i+1]>='A'&&A[i+1]<='Z'))
			{
					if(A[i-1]<A[i+1])
				{
					for (j=1;j<=A[i+1]-A[i-1];j++)
					{
						printf ("%c",A[i-1]+j);
					}
					i++;
				}
			}
			else if((A[i-1]>='0'&&A[i-1]<='9')&&(A[i+1]>='0'&&A[i+1]<='9'))
			{
					if(A[i-1]<A[i+1])
				{
					for (j=1;j<=A[i+1]-A[i-1];j++)
					{
						printf ("%c",A[i-1]+j);
					}
					i++;
				}
			}
			else printf ("%c",A[i]);
		}
		else printf ("%c",A[i]);
	}

	
	
	
	return 0;
}



