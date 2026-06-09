#include<stdio.h>
#include<string.h>
int main()
{
	char c[100]={'\0'},*p;
	gets(c);
	p=c;
	int i=2,j,k;
	for(j=strlen(c)-1;c[j]=='0';j--);
		c[j+1]='\0';
	if(c[0]=='0')
	{
		while(c[i]=='0')
			i++;
		printf("%c",c[i]);
		if(i!=strlen(c)-1)  printf(".");
		printf("%se",c+i+1);
		printf("%d",-i+1);
	}
	else if(c[1]=='.')
		printf("%se0",c);
	else 
	{
		printf("%c.",c[0]);
		for(k=strlen(c)-1;c[k]!='.';k--);
			c[k]='\0';
		printf("%s",c+1);
		printf("%se%d",c+k+1,k-1);	
	}		
	return 0;
} 

