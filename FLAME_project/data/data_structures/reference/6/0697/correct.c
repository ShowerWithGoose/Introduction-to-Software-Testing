#include<stdio.h>
int sta[110],top;

signed main()
{
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==-1)return 0;
        if(op== 1)
        {
            scanf("%d",&num);
            if(top==100)printf("error ");
            else sta[++top]=num;
        }
        if(op==0)
        {
            if(top==0)printf("error ");
            else printf("%d ",sta[top--]);
        }
    }
}
