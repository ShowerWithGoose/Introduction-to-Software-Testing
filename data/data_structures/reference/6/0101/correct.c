#include<stdio.h>
#define M 100
typedef int TYpe; 
TYpe Stack[M];
int top=-1;

int Stack_Full(int top)
{
	return top==M-1;
}

int Stack_Empty(int top)
{
	return top==-1;
}

int Stack_Push(TYpe Stack[],int *top,TYpe item)
{
	if(Stack_Full(*top)) 
		return 0;
	else{
		Stack[++*top]=item;
		return 1;
	}
}

int Stack_Pop(TYpe Stack[],int *top,TYpe *item)
{
	if(Stack_Empty(*top)) 
		return 0;
	else{
		*item=Stack[(*top)--];
		return 1;
	}
}
int main(){
    int n,item,i,p;
    while(1){
        scanf("%d",&n);
        i=-1;
        if(n==1){
            scanf("%d",&item);
            i=Stack_Push(Stack,&top,item);
            if(i==0)
                printf("error ");
        }
        else if(n==0){
            i=Stack_Pop(Stack,&top,&p);
            if(i==0)
                printf("error ");
            else
                printf("%d ",p);
            }
        else
            return 0;
    }
}
