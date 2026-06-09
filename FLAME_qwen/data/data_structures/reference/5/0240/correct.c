#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
    int coe;//系数 
    int pow;//指数 
} a[50000],b[50000],p[50000];
typedef struct node *Nodeptr;
int ans=0,cnt=0,k=0,i,j;
char ch=' ';
int cmp(const void *a, const void *b)             //排序，按指数从大到小排序
{
    Nodeptr c = (Nodeptr)a;
    Nodeptr d = (Nodeptr)b;
    return d->pow-c->pow;
}
int main()
{
    while(ch!='\n')                                   //读入第一个多项式
    {
        scanf("%d%d%c",&a[ans].coe,&a[ans].pow,&ch);
        ans++;
    }
    ch=' ';
    while(ch!='\n')                                   //读入第二个多项式
    {
        scanf("%d%d%c",&b[cnt].coe,&b[cnt].pow,&ch);
        cnt++;
    }
    for(i=0;i<ans;i++)                       //两个多项式相乘，系数相乘，指数相加
        for(j=0;j<cnt;j++)
    {
        p[k].coe=a[i].coe*b[j].coe;
        p[k].pow=a[i].pow+b[j].pow;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);                     //从大到小对指数排序
    for(i=0;i<k;i++)
    {
        if(p[i].pow==p[i+1].pow&&p[i].pow!=0)        //合并指数相同的项数
        {
            p[i+1].coe=p[i+1].coe+p[i].coe;
            p[i].coe=0;
        }
    }
    for(i=0;i<k;i++)
        if(p[i].coe!=0)
        printf("%d %d ",p[i].coe,p[i].pow);
    return 0;
}

