#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
typedef int ElemType;
ElemType stack[MAX];
int top=-1;
void push(ElemType s[],ElemType i)
{
    if(isfull()){
        printf("error ");
        }
    else{
        s[++top]=i;
    }
}
int isfull()
{
    return top==MAX-1;
}
int isempty()
{
    return top==-1;
}
ElemType pull(ElemType s[])
{
    if(isempty()){
         printf("error ");
         }
    else{
        printf("%d ",s[top]);
        return s[top--];
    }
}
int main()
{
    int n;
    ElemType a;
    while((scanf("%d",&n))!=-1){
        if(n==1){
            scanf("%d",&a);
            push(stack,a);
        }
        if(n==0){
            pull(stack);
        }
        if(n==-1){
            break;
        }
    }
    return 0;
}



