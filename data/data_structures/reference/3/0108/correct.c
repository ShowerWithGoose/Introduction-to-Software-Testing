#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(void){
	char A[100]={},ch;
	int minus=0,i=0,bit;
	A[0]=getchar();
	if(A[0]=='-')
	{
		A[0]=0;
		minus=true;
	}
	else i++;
	while((ch=getchar())!='\n')
	{
		A[i]=ch;
		i++;
	}	
	if(minus) putchar('-');
	if(A[0]=='0')
	{
		for(i=0;A[i]=='0'||A[i]=='.';i++);
		bit=i-1;
		printf("%c",A[i]);
		i++;
		if(i!=strlen(A)) putchar('.');
		while(i<strlen(A))
		{
			putchar(A[i]);
			i++;
		}
		printf("e-%d",bit);
	}
	else
	{
		for(i=0;A[i]!='.';i++);
		bit=i-1;
		printf("%c.",A[0]);
		i=1;
		while(i<strlen(A))
		{
			if(A[i]!='.') putchar(A[i]);
			i++;
		}
		printf("e%d",bit);
	}
} 

