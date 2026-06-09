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
int isblank(int x) // @@ This function name conflicts with the standard library function isblank() declared in <ctype.h>. The compiler interprets it as a redefinition, causing a compilation error.
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