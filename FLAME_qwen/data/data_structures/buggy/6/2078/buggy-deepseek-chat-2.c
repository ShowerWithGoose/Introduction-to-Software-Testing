#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE]={};
int top;
void initStack()
{
    top=-1;
}
int isEmpty()
{
    return top==-1;
} 
int isFull() 
{
    return top==MAXSIZE-1;
}
void push(int num)
{
    if(isFull()){printf("error ");}
    else{
        stack[++top]=num;
    }
}
void pop()
{
    int item;
    if(isEmpty()){printf("error ");}
    else
    {
        item=stack[top--];
        printf("%d ",item);
    }
}
int main()
{
    int flag=0,num=0;
    initStack; // @@ [Error: Missing parentheses to call the function initStack(). Should be initStack();]
    while(scanf("%d",&flag)!=EOF){
        if(flag==1){
            scanf("%d",&num);
            push(num);
        }
        else if(flag==0){
            pop();
        }
        else if(flag==-1){break;}
    }
    return 0;
}