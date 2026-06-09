#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define eps 1e-8
int a[100]={0};
int isfull(int x)
{
    return x==99;
}
int isblank(int x) @@ // The function name 'isblank' conflicts with the standard library function declared in <ctype.h>, causing a compilation error due to redefinition or incorrect declaration syntax when the compiler tries to reconcile the two.
{
    return x==-1;
     } 
int main() {
    int n=0,m=0,top=-1;
    scanf("%d",&n);
    while(n!=-1)
    {
        if(n==1)
        {
            scanf("%d",&m);
            if(isfull(top)==1)
             printf("error ");
            else
            {
                top++;
                a[top]=m;
            }
        }
        else if(n==0)
        {
            if(isblank(top)==1) printf("error ");
            else 
            {
                printf("%d ",a[top]);
                top--;
             } 
        }
        scanf("%d",&n);
    }
    return 0;
}