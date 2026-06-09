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
            if(tt==0) printf("erroer "); // @@ Typo in the error message string "erroer", it should be "error"
            else printf("%d ",stk[tt--]);
        }
        else if(op==1)
        {
            scanf("%d",&x);
            if(tt==maxsize) printf("error "); // @@ Missing a continue statement to skip the push operation when the stack is full
            stk[++tt]=x;
        }
    }
    return 0;
 }