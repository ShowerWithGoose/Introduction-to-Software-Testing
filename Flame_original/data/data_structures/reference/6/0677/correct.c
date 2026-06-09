#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
int main()
{
	int op,num;
	int stack[120]={};
	int top=-1;
	while(scanf("%d",&op))
	{
		
		if(op==1)
			scanf("%d",&num);
		else if(op==0){
			if(top==-1)		//≈–∂œ’ªø’ 
				printf("error ");
			else
				printf("%d ",stack[top--]);
			continue;
		}else
			break;
		
		if(top==max-1)	//≈–∂œ’ª «∑Ò¬˙ 
			printf("error ");
		else
			stack[++top]=num;
	}
	return 0;
}

