#include<stdio.h>
#include<string.h>
#define MAXSIZE 100

int main()
{
	int stack[MAXSIZE+1];
	int op,top=-1,num;
	scanf("%d",&op);
	while(op!=-1){
		if(op==1){
			scanf("%d",&num);
			if(top==MAXSIZE-1){
				printf("error ");
			}
			else stack[++top]=num;
		}
		else if(op==0){
			if(top==-1){
				printf("error ");
			}
			else printf("%d ",stack[top--]);
		}
		scanf("%d",&op); 
	}
	return 0;
}

