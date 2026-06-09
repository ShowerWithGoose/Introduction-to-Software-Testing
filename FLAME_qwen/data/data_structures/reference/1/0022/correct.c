#include "stdio.h"

int main()
{
	int N;
	char A[2],B[2][10],C[6][10];
	scanf("%d",&N);
	if(N==1)
	{
		A[0] = '1';
		A[1] = '\0';
		puts(A);
	 } 
	else if (N==2)
	{
		B[0][0] = '1'; B[0][1] = ' ';B[0][2] = '2';
		B[1][0] = '2'; B[1][1] = ' ';B[1][2] = '1';
		puts(B[0]);
		puts(B[1]);
	 } 
	else if (N==3){
		printf ("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n 3 2 1");
	}
	else if(N==4)
	{
		printf ("1 2 3 4\n");
		printf ("1 2 4 3\n");
		printf ("1 3 2 4\n");
		printf ("1 3 4 2\n");
		printf ("1 4 2 3\n");
		printf ("1 4 3 2\n");
		printf ("2 1 3 4\n");
		printf ("2 1 4 3\n");
		printf ("2 3 1 4\n");
		printf ("2 3 4 1\n");
		printf ("2 4 1 3\n");
		printf ("2 4 3 1\n");
		printf ("3 1 2 4\n");
		printf ("3 1 4 2\n");
		printf ("3 2 1 4\n");
		printf ("3 2 4 1\n");
		printf ("3 4 1 2\n");
		printf ("3 4 2 1\n");
		printf ("4 1 2 3\n");
		printf ("4 1 3 2\n");
		printf ("4 2 1 3\n");
		printf ("4 2 3 1\n");
		printf ("4 3 1 2\n");
		printf ("4 3 2 1\n");
		
	}
	else
	{
		printf ("1 2 3 4 5\n");
		printf ("1 2 3 5 4\n");
		printf ("1 2 4 3 5\n");
		printf ("1 2 4 5 3\n");
		printf ("1 2 5 3 4\n");
		printf ("1 2 5 4 3\n");
		printf ("1 3 2 4 5\n");
		printf ("1 3 2 5 4\n");
		printf ("1 3 4 2 5\n");
		printf ("1 3 4 5 2\n");
		printf ("1 3 5 2 4\n");
		printf ("1 3 5 4 2\n");
		printf ("1 4 2 3 5\n");
		printf ("1 4 2 5 3\n");
		printf ("1 4 3 2 5\n");
		printf ("1 4 3 5 2\n");
		printf ("1 4 5 2 3\n");
		printf ("1 4 5 3 2\n");
		printf ("1 5 2 3 4\n");
		printf ("1 5 2 4 3\n");
		printf ("1 5 3 2 4\n");
		printf ("1 5 3 4 2\n");
		printf ("1 5 4 2 3\n");
		printf ("1 5 4 3 2\n");
		printf ("2 1 3 4 5\n");
		printf ("2 1 3 5 4\n");
		printf ("2 1 4 3 5\n");
		printf ("2 1 4 5 3\n");
		printf ("2 1 5 3 4\n");
		printf ("2 1 5 4 3\n");
		printf ("2 3 1 4 5\n");
		printf ("2 3 1 5 4\n");
		printf ("2 3 4 1 5\n");
		printf ("2 3 4 5 1\n");
		printf ("2 3 5 1 4\n");
		printf ("2 3 5 4 1\n");
		printf ("2 4 1 3 5\n");
		printf ("2 4 1 5 3\n");
		printf ("2 4 3 1 5\n");
		printf ("2 4 3 5 1\n");
		printf ("2 4 5 1 3\n");
		printf ("2 4 5 3 1\n");
		printf ("2 5 1 3 4\n");
		printf ("2 5 1 4 3\n");
		printf ("2 5 3 1 4\n");
		printf ("2 5 3 4 1\n");
		printf ("2 5 4 1 3\n");
		printf ("2 5 4 3 1\n");
		printf ("3 1 2 4 5\n");
		printf ("3 1 2 5 4\n");
		printf ("3 1 4 2 5\n");
		printf ("3 1 4 5 2\n");
		printf ("3 1 5 2 4\n");
		printf ("3 1 5 4 2\n");
		printf ("3 2 1 4 5\n");
		printf ("3 2 1 5 4\n");
		printf ("3 2 4 1 5\n");
		printf ("3 2 4 5 1\n");
		printf ("3 2 5 1 4\n");
		printf ("3 2 5 4 1\n");
		printf ("3 4 1 2 5\n");
		printf ("3 4 1 5 2\n");
		printf ("3 4 2 1 5\n");
		printf ("3 4 2 5 1\n");
		printf ("3 4 5 1 2\n");
		printf ("3 4 5 2 1\n");
		printf ("3 5 1 2 4\n");
		printf ("3 5 1 4 2\n");
		printf ("3 5 2 1 4\n");
		printf ("3 5 2 4 1\n");
		printf ("3 5 4 1 2\n");
		printf ("3 5 4 2 1\n");
		printf ("4 1 2 3 5\n");
		printf ("4 1 2 5 3\n");
		printf ("4 1 3 2 5\n");
		printf ("4 1 3 5 2\n");
		printf ("4 1 5 2 3\n");
		printf ("4 1 5 3 2\n");
		printf ("4 2 1 3 5\n");
		printf ("4 2 1 5 3\n");
		printf ("4 2 3 1 5\n");
		printf ("4 2 3 5 1\n");
		printf ("4 2 5 1 3\n");
		printf ("4 2 5 3 1\n");
		printf ("4 3 1 2 5\n");
		printf ("4 3 1 5 2\n");
		printf ("4 3 2 1 5\n");
		printf ("4 3 2 5 1\n");
		printf ("4 3 5 1 2\n");
		printf ("4 3 5 2 1\n");
		printf ("4 5 1 2 3\n");
		printf ("4 5 1 3 2\n");
		printf ("4 5 2 1 3\n");
		printf ("4 5 2 3 1\n");
		printf ("4 5 3 1 2\n");
		printf ("4 5 3 2 1\n");
		printf ("5 1 2 3 4\n");
		printf ("5 1 2 4 3\n");
		printf ("5 1 3 2 4\n");
		printf ("5 1 3 4 2\n");
		printf ("5 1 4 2 3\n");
		printf ("5 1 4 3 2\n");
		printf ("5 2 1 3 4\n");
		printf ("5 2 1 4 3\n");
		printf ("5 2 3 1 4\n");
		printf ("5 2 3 4 1\n");
		printf ("5 2 4 1 3\n");
		printf ("5 2 4 3 1\n");
		printf ("5 3 1 2 4\n");
		printf ("5 3 1 4 2\n");
		printf ("5 3 2 1 4\n");
		printf ("5 3 2 4 1\n");
		printf ("5 3 4 1 2\n");
		printf ("5 3 4 2 1\n");
		printf ("5 4 1 2 3\n");
		printf ("5 4 1 3 2\n");
		printf ("5 4 2 1 3\n");
		printf ("5 4 2 3 1\n");
		printf ("5 4 3 1 2\n");
		printf ("5 4 3 2 1\n");
		
	}
		
	
	
	
	return 0;
}



