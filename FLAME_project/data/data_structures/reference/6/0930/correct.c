#include<stdio.h>
#include<string.h>
#define MAX 100
int stack[100];
int isEmpty(int);
int isFull(int);
int main()
{
	int op,num,top=-1;
	while(1){
		scanf("%d",&op);
		if(op==-1)
		    break;
		else if(op==1){
			scanf("%d",&num);
			top++;
			if(isFull(top)){
				printf("error ");
				top--;
			}
		    else
			    stack[top]=num;	    
		}
		else if(op==0){
			if(isEmpty(top))
				printf("error ");
			else
			    printf("%d ",stack[top--]);
		}
	}
	return 0;
}
int isEmpty(int top)
{
	return top==-1;
}
int isFull(int top)
{
	return top==MAX-1;
}

