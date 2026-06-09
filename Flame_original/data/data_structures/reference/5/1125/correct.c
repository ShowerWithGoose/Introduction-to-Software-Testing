#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a,b;
}o[100],p[100],ans[10000];
int cmp(const void *a,const void*b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    return d->b-c->b;
}
int main()
{
    int n1=0;
    while(1)
    {
        char c;
        n1++;
        scanf("%d%d%c",&o[n1].a,&o[n1].b,&c);
        if(c=='\n')
        {
            break;
        }
    }
    int n2=0;
    while(1)
    {
        char c;
        n2++;
        scanf("%d%d%c",&p[n2].a,&p[n2].b,&c);
        if(c=='\n')
        {
            break;
        }
    }
    int j,num=0,i;
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            num++;
            ans[num].a=o[i].a*p[j].a;
            ans[num].b=o[i].b+p[j].b;
        }
    }
    qsort(ans+1,num,sizeof(ans[0]),cmp);
    int count=0;
    for(i=1;i<=num;i++)
    {
        if(ans[i].b!=ans[i+1].b)
        {
            printf("%d %d ",ans[i].a,ans[i].b);
        }
        else
        {
            count=0;
            while(ans[i].b==ans[i+1].b&&i<=num)
            {
                count+=ans[i].a;
                i++;
            }
            count+=ans[i].a;
            printf("%d %d ",count,ans[i].b);
        }
    }
    return 0;
}
