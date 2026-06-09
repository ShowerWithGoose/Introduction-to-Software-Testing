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
    if(top!=max) // @@ The condition should be `top != max-1` or `top < max-1` because the stack indices go from 0 to 99 (max-1). When top is 99, the stack is full, and pushing would cause an out-of-bounds access.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do
    {
        if(n==1) // @@ The variable `n` is uninitialized on the first iteration of the do-while loop. It should be read before being used in conditions.
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