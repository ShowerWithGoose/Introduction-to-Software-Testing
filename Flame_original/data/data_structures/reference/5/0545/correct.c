#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 130000
struct node
{
    int co;                     //两个值，一个存系数，一个存指数
    int en;
} a[MAX],b[MAX],p[MAX],q[MAX];

int cnta = 0,cntb= 0;
char c = ' ';
int cmp(const void *a, const void*b)             //排序，按指数从大到小排序
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->en - c->en;
}
int main()
{
    while( c != '\n')                                   //读入第一个多项式
    {
        scanf("%d%d%c",&a[cnta].co,&a[cnta].en,&c);
        ++cnta;
    }
    c = ' ';
    while( c != '\n')                                   //读入第二个多项式
    {
        scanf("%d%d%c",&b[cntb].co,&b[cntb].en,&c);
        ++cntb;
    }
    int k = 0;
    for(int i = 0; i < cnta; i++)                       //两个多项式相乘，系数相乘，指数相加
        for(int j = 0; j < cntb; j++)
    {
        p[k].co = a[i].co*b[j].co;
        p[k].en = a[i].en + b[j].en;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmp);                     //从大到小对指数排序
    for(int i = 0; i < k; i++)
    {
        if(p[i].en == p[i+1].en && p[i].en != 0)        //合并指数相同的项数
        {
            p[i+1].co += p[i].co;
            p[i].co = 0;
        }
    }
    for(int i = 0; i < k; i++)
        if(p[i].co != 0)
        printf("%d %d ",p[i].co,p[i].en);               //输出就完事了
    return 0;
}
/*
10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0
*/

