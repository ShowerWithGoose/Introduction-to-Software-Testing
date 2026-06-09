#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int stack[101];
int top=-1;
void Push(int elem)
{
	if(top==99)
	{
		printf("error ");
		//exit(1);
	}
	stack[++top]=elem;
}
void Pop()
{
	if(top<=-1)
	{
		printf("error ");
		//exit(1);
	}
	else printf("%d ",stack[top--]);
}
int main()
{
	int flag,elem,i,j,k;
	while(scanf("%d",&flag)!=-1)
	{
		if(flag==1)
		{
			scanf("%d",&elem);
			Push(elem);
		}
		else if(flag==0)
		{
			Pop();
		}
		else break;
	}
 } 

