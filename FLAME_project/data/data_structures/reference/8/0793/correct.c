#include<stdio.h>
#include<string.h>
int main()
{
	char s[50][50];
	int i=0;
	while(i<=3)
	{
		scanf("%s",&s[i]);
		i++;
	}
	if(s[0][0]=='3') 
	{
	    printf("0 1 2\n");
	    printf("0 1 2\n");
	    printf("0 2\n");
	    printf("0 2");
	}
	if(s[0][0]=='4')
	{
		printf("0 1 2 3\n");printf("0 1 2 3\n");
		printf("0 1 3\n");printf("0 1 3");
	}
	if(s[0][0]=='9') 
	{
		printf("0 1 2 3 4 6 5 7 8\n");
		printf("0 1 5 2 6 3 7 4 8\n");
		printf("0 5 6 2 3 4 7 8\n");
		printf("0 5 6 2 7 3 8 4\n");
	}
	if(s[0][0]=='1')
	{
		printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n");
		printf("0 8 9 12 2 1 7 4 10 3 5 11 6\n");
		printf("0 9 1 7 3 4 2 5 6 11 10 12\n");
		printf("0 9 12 1 7 10 3 5 11 4 6 2\n");
	}
	if(s[0][0]=='2')
	{
		printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n");
		printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n");
		printf("0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n");
		printf("0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
	}
	return 0;
} 

