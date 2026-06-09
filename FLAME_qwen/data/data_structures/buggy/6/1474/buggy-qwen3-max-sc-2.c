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
    if(top!=max) 
    s[++top]=item;
    else 
    printf("error ");
}
int main ()
{
    int n,thing,ans,flag;
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
} // @@ [The variable 'n' is used uninitialized in the first iteration of the loop. The 'do-while' loop reads 'n' only at the end of each iteration, so the first check of 'n' (e.g., if(n==1)) uses an indeterminate value, leading to undefined behavior. This can cause incorrect operation interpretation or crashes. Additionally, the condition in push() should be 'top < max - 1' or 'top != max - 1' because valid indices are 0 to max-1; current condition 'top != max' allows top to become max, causing buffer overflow. Also, when pop returns -1 to indicate error, if the actual popped value was -1 (a valid integer), it would be mistaken for an error, leading to missing output.]