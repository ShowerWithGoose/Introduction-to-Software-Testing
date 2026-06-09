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
    if(top!=max) // @@ The condition should be `top < max-1` or `top != max-1`. As written, when top is 99 (stack full), the condition is true, causing a push beyond array bounds.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do // @@ The do-while loop reads input at the end, so on the first iteration `n` is uninitialized. This leads to undefined behavior and incorrect processing of operations.
    {
        if(n==1) // @@ On the first iteration, `n` is uninitialized, causing the program to compare an arbitrary value.
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