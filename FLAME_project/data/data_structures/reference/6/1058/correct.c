#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265
#define MAX 100

int main()
{
	int top=-1,a[MAX],c,x;
	while(scanf("%d",&c)!=-1)
	{
		switch(c)
		{
			case 1:
				if(top==MAX-1)
				{
					printf("error ");
					break;
				}
				scanf("%d",&x);
				a[++top]=x;
				break;
			case 0:
				if(top==-1)
				{
					printf("error ");
					break;
				}
				x=a[top--];
				printf("%d ",x);
				break;	
		}
	 } 
	return 0;
}



