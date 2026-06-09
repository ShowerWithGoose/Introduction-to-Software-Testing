#include <stdio.h>
int stack[100],top=0;
int main()
{
    int a,b;
    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&b);
            if(top==100) printf("error ");
            else stack[top++]=b;
        }
        else if(a==0)
        {
            if(top==0) printf("error ");
            else printf("%d ",stack[(top--)-1]);
        }
        else if(a==-1) break;
    }
    return 0;
}
