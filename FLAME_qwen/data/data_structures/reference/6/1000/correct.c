#include <stdio.h>
#define MAXN 1000
int cnt,tl;
int que[MAXN];

int main()
{
    int a,b;
    while(scanf("%d",&a))
    {
        if(a==-1)break;
        if(a==1)
        {
            scanf("%d",&b);
            que[++tl]=b;
        }
        else
        {
            if(!tl) printf("error ");
            else
            {
                printf("%d ",que[tl]);
                tl--;
            } 
        }
    }
    return 0;
}
