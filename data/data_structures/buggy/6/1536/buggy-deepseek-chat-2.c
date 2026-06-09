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
            if(tt==maxsize) printf("error ");
            stk[++tt]=x; // @@ Missing continue or else after the full check; when stack is full, the push should not occur, but here it still executes stk[++tt]=x, causing overflow.
        }
    }
    return 0;
 }