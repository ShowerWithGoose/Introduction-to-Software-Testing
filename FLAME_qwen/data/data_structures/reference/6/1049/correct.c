
#include<stdio.h>
#include<math.h>
#include<string.h>
int stack[101];
int top=-1;
int item;
int isfull(int top)
{
	if(top>=99) return 1;
	else return 0;
}
int isempty(int top)
{
	if(top==-1) return 1;
	else return 0;
}
void pushstock(int item)
{
	if(isfull(top)) printf("error ");
	else stack[++top]=item;
}
void popstack()
{
	if(isempty(top)) printf("error ");
	else printf("%d ",stack[top--]);
}
int main()
{	
	int a[202];
	int i=-1;
	do
	{
		scanf("%d",&a[++i]);
	}while(a[i]!=-1);
	for(i=0;a[i]!=-1;i++)
	{
		if(a[i]==1) pushstock(a[++i]);
		else if(a[i]==0) popstack();
	}
	

return 0;
}




