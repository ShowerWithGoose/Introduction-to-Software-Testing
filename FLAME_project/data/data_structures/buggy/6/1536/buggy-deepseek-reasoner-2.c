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
            if(tt==0) printf("erroer "); // @@ typo: should be "error " instead of "erroer "
            else printf("%d ",stk[tt--]);
        }
        else if(op==1)
        {
            scanf("%d",&x);
            if(tt==maxsize) printf("error "); // @@ missing logic: should skip the subsequent push when stack is full
            stk[++tt]=x; // @@ this line executes unconditionally, causing overflow and incorrect state if stack is full
        }
    }
    return 0;
 }