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
    if(top!=max) // @@ The condition for checking if the stack is full is incorrect. It should be `top == max - 1` because `top` is 0-indexed. Currently, it allows pushing when `top` is `max-1` (full) but fails only when `top` is `max` (out of bounds), or incorrectly allows push when `top` is `max-1` if the check was intended to be `top < max`. Actually, `top != max` is true when `top` is `max-1`, so it pushes to `s[max]`, which is out of bounds. The correct check for full is `top == max - 1`.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do
    {
        if(n==1) // @@ Variable 'n' is used uninitialized in the first iteration of the do-while loop. The scanf happens at the end of the loop, so the first check uses garbage value.
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