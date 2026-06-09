#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10

int main()
{
//	char a[100];
//	int i;
	int x,y,z;
	z=0;
	char x1,x2,x3='+';
	while (1)
	{
		scanf("%d %c",&x,&x1);
	/*	if(x1=='=')
			{
				printf("%d",x);
				return 0;
			}*/
		while(x1=='*'||x1=='/')
		{
			scanf("%d %c",&y,&x2);
			if(x1=='*')
			{
				x=x*y;
		//		continue;
				
			}
			if(x1=='/')
			{
				x=x/y;
			}
		//		continue
				x1=x2;
			
			
		}
		if(x3=='+')
		{
			z=z+x;
		}
		if(x3=='-')
		{
			z=z-x;
		}
		x3=x1;
		if(x3=='=')
		{
			printf("%d",z);
			return 0;
		}
	 } 
/*	for(i=0;a[i]!='\0';i++)
	{
		if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]&&a[i]=='-')
		{
			for(int j=1;j<(a[i+1]-a[i-1]);j++)
			printf("%c",a[i-1]+j);	
		}
		else
		printf("%c",a[i]);
	}*/
//	printf("%c",a[z]);
	return 0;
	
 }

 


