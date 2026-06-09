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
    if(top!=max) // @@ Incorrect full condition: allows top to reach 100, causing out-of-bounds access to s[100]. Should be top < max - 1 or top != 99.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do // @@ n is uninitialized on the first iteration, causing undefined behavior. Should use a while loop instead.
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
    }while(scanf("%d",&n)!=EOF); // @@ Loop executes body before reading n, leading to incorrect flow. Should be while(scanf("%d",&n)!=EOF) { ... }
            
    
return 0;
}