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
    if(top!=max) // @@ condition should check if stack is full (top == max-1); current condition allows out-of-bounds write when top == max-1
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag; // @@ variable 'flag' is declared but never used
    do // @@ first iteration uses uninitialized 'n', leading to undefined behavior
    {
        if(n==1) // @@ 'n' is uninitialized in the first iteration
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