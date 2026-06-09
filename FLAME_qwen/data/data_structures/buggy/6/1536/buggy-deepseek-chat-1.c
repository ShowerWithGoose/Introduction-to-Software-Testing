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
            if(tt==0) printf("erroer "); // @@ Typo: "erroer" should be "error" to match the problem specification.
            else printf("%d ",stk[tt--]);
        }
        else if(op==1)
        {
            scanf("%d",&x);
            if(tt==maxsize) printf("error "); // @@ Missing continue statement: after printing "error", the program should skip the push operation, but it still executes stk[++tt]=x, which may cause a stack overflow.
            stk[++tt]=x;
        }
    }
    return 0;
 }