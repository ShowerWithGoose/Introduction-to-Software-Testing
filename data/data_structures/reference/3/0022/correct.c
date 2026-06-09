#include "stdio.h"

int main(){
	int i,j,k;
	char A[100];
	gets(A);
	if (A[0] != '0'&&A[1] == '.')
	{
		 for (j=0;A[j]!='\0';j++)
	 	{
	 	 	printf ("%c",A[j]);
		}
		printf ("e0");
	}
	else if(A[1] == '.'&&A[0] == '0')
	{	
		for (i = 2;A[i]=='0';i++)
		 ;
		 A[0] = A[i];
		 for (j=2;A[j]!='\0';j++)
		 {
	 		A[j] = A[j+i-1];
	 	 }
	 	 if(A[2] == '\0') A[1] = '\0';
	 	 for (j=0;A[j]!='\0';j++)
	 	 {
	 	 	printf ("%c",A[j]);
		}
		 printf ("e-%d",i-1);
		
	}
	else{
		 for (i = 0;A[i]!='.';i++)
		 ;
		 for (j=i;j>=1;j--)
		 {
	 		A[j] = A[j-1];
	 	 }
	 	 A[1] = '.';
	 	 for (j=0;A[j]!='\0';j++)
	 	 {
	 	 	printf ("%c",A[j]);
		}
		 printf ("e%d",i-1);
	}
		
	
	return 0;
}



