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
            if(tt==0) printf("erroer "); // @@ Typo in "erroer" should be "error"
            else printf("%d ",stk[tt--]);
        }
        else if(op==1)
        {
            scanf("%d",&x);
            if(tt==maxsize) printf("error ");
            stk[++tt]=x; // @@ Pushing after checking full condition, but tt is incremented even when stack is full; also, stack uses 1-based indexing but initial tt=0 implies empty stack, so max capacity check should be tt >= maxsize before increment
        }
    }
    return 0;
 }