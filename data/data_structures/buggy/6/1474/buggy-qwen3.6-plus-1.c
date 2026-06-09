#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
int pop(int s[])
{
    if(top!=-1) 
    return s[top--];
    else{
    printf("error ");
    return -1;
    }
}
void push(int s[],int item)
{
    if(top!=max) // @@ Error: The stack is full when top equals 99 (max-1). Checking top!=max allows top to increment to 100, causing an out-of-bounds array access.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do // @@ Error: The variable 'n' is used in the condition 'if(n==1)' before being initialized or read from input, leading to undefined behavior on the first iteration.
    {
        if(n==1)
        {
            scanf("%d",&thing);
            push(stack,thing);
        }
        else if(n==-1)
        break;
        else if(n==0){
        ans=pop(stack);
        if(ans!=-1){
        printf("%d ",ans);}
        }
    }while(scanf("%d",&n)!=EOF);
            
    
return 0;
}