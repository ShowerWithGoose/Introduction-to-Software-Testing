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
    if(top!=max) // @@ Condition incorrectly allows push when stack is full (top == 99), leading to out-of-bounds write at s[100]. Should be top < max-1 or top != max-1.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag; // @@ 'n' is uninitialized, will be used in the first iteration of the do-while loop, causing undefined behavior. It should be initialized (e.g., read before the loop) or the loop structure should be changed.
    do
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