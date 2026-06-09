#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8
int a[100]={0};
int top=-1;
int isfull()
{
	return top==99;
}

int isblank0()
{
	return top==-1;
	 } 
int main() {
	int n=0,m=0;
	scanf("%d",&n);
	while(n!=-1)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(isfull()==1)
			 printf("error ");
			else
			{
				top++;
				a[top]=m;
			}
		}
		else if(n==0)
		{
			if(isblank0()==1) printf("error ");
			else 
			{
				printf("%d ",a[top]);
				top--;
			 } 
		}
		scanf("%d",&n);
	}
	return 0;
}


