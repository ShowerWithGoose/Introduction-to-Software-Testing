#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void PopStk(int *stk,int * ptop);
void PushStk(int *stk,int * ptop);
int main()
{
	int conduct,top=0;
	int stk[105];
	while(~scanf("%d",&conduct))
	{
		switch (conduct)
		{
			case 1:PushStk(stk,&top);break;
			case 0:PopStk(stk,&top);break;
			case -1:return 0;
		}
	}
	return 0;
 } 
void PushStk(int *stk,int * ptop)
{
	int get;
	scanf("%d",&get);
	if((*ptop)>=MAX) printf("error ");
	else stk[++(*ptop)]=get;
	return;
}
void PopStk(int *stk,int * ptop)
{
	if((*ptop)<=0) printf("error ");
	else {
		printf("%d ",stk[(*ptop)--]);
	}
	return;
}

