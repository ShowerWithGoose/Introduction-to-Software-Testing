#include<stdio.h>
#include<string.h> 
int main() 
{
	char a[100];
	gets(a); 
	int i;
	if(a[0]=='-')
	{
		printf("-");
		for(i=0;a[i]!='\0';i++)
		a[i]=a[i+1];
	}
	if(a[0]!='0')
	{
	int b=strchr(a,'.')-a;	
		for(i=b;a[i]!='\0';i++)
			a[i]=a[i+1];
	printf("%c.",a[0]) ;
	for(i=1;a[i]!='\0';i++)
	printf("%c",a[i]);
	printf("e%d",b-1);	
	} 
	if(a[0]=='0')
	{
		int c;//c-2
		for(c=2;a[c]=='0';c++)
		;
		printf("%c",a[c]);
			if(a[c+1]!='\0')
			{
			printf(".");
			for(i=c+1;a[i]!='\0';i++)	
			printf("%c",a[i]);	
			}
		printf("e-%d",c-1);
	}
	return 0;
}

