#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 100
int z[maxsize],top=-1;
void push(int z[],int item)
{
	if(top==maxsize-1)
	printf("error ");
	else
	z[++top]=item;
}
void pop(int z[])
{
	if(top==-1)
	printf("error ");
	else
	printf("%d ",z[top--]);
}
int main()
{
	int i,j,s[500];
	for(i=0;;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]==-1)
		break;
	}
	for(j=0;j<i;j++)
	{
		if(s[j]==1)
		push(z,s[++j]);
		else if(s[j]==0)
		pop(z);
	}
	return 0;
}

