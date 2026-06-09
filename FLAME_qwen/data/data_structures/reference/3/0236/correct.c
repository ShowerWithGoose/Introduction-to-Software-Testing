#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i, step, j;
	gets(a);
	if(a[0]=='0')
	{
		for(i=2;a[i]=='0';i++);
		step=i-1;
		if(i==strlen(a)-1)
		{
		 printf("%ce-%d", a[i],step);
		}
		else 
		{
			printf("%c.", a[i]);
			for(i=i+1;i<strlen(a);i++)
			printf("%c", a[i]);
			printf("e-%d", step);
		}
	}
	else if(strlen(a)==1)  printf("%ce0", a[0]);
	else
	{
		for(i=1;a[i]!='.'; i++);
		step=i-1;
		printf("%c.", a[0]);
		for(j=i;a[j]!='\0';j++)
		{
			a[j]=a[j+1];
		}
		for(i=1;i<strlen(a);i++)
		printf("%c", a[i]);
		printf("e%d", step);
	}
 } 

