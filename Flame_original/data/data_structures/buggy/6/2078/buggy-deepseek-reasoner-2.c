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
    initStack; // @@ Missing parentheses: should be `initStack();` to actually call the function. Without the call, `top` remains 0 (default global initialization) instead of -1, causing stack operations to start from the wrong position.
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