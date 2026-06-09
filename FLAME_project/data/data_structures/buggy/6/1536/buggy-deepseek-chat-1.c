#include<stdio.h>
#define maxsize 100
int stk[5000],tt=0;
int main()
{
    int op,x;
    while(scanf("%d",&op))
    {
        if(op==-1) break;
        else if(op==0) 
        {
            if(tt==0) printf("erroer "); // @@ Typo: should be "error " instead of "erroer "
            else printf("%d ",stk[tt--]);
        }
        else if(op==1)
        {
            scanf("%d",&x);
            if(tt==maxsize) printf("error "); // @@ Missing handling: when stack is full, the push should not be performed, but here it still executes stk[++tt]=x after printing error
            stk[++tt]=x;
        }
    }
    return 0;
 }