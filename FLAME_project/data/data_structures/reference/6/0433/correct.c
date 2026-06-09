#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int stack[100];
int top=-1;
void InStack()
{
	int m;
	scanf("%d",&m);
	if(top==99)
		printf("error ");
	else
		stack[++top]=m;
}
void OutStack()
{
	if(top==-1)
		printf("error ");
	else
		printf("%d ",stack[top--]);
}
int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if(x==1)	InStack();
		else if(x==0)	OutStack();
		else	break;
	}
	return 0;
} 

