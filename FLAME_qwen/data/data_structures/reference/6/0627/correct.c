#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define M 100
int a[M];
int top,temp;
int empty(int);
int full(int);
int pop(int[]);
int push(int[],int);
int main()
{
	int m,n; 
	top=-1;
	while(scanf("%d",&n)!=-1)
	{
		
		
		if(n==1)
		{
			scanf("%d",&m);
			if(push(a,m)!=0); 
			else{
				printf("error ");
			}
		}
		if(n==0)
		{
			if(pop(a)!=0)
			{
				printf("%d ",temp);
			}
			else{
				printf("error ");
			}
		}
		if(n==-1)
		break;
	}
	return 0;
} 
int empty(int top)
{
	return top==-1;
}
int full(int top)
{
	return top==M-1;
}
int push(int* a,int m)
{
	if(full(top))
	{
		return 0;
	}
	else{
		a[++top]=m;
		return 1;
	}
}
int pop(int* a)
{
	if(empty(top))
	{
		return 0;
	}
	else{
		temp=a[top--];
		return 1;
	}
}

