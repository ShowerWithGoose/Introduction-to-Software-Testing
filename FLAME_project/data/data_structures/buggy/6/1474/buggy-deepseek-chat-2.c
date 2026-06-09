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
    if(top!=max) // @@ The condition should be `top != max-1` to check if the stack is full (since max is 100, top ranges from -1 to 99). Using `top != max` will allow pushing when top is 99 (full), causing a buffer overflow.
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
    do
    {
        if(n==1) // @@ The variable `n` is used before being initialized. On the first iteration of the do-while loop, `n` has an undefined value, which may cause incorrect behavior or a crash.
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