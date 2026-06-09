#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int co;                     //两个值，一个存系数，一个存指数
    int en;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Node a[101230],b[114121],p[123124],q[124124];
int cnta = 0,cntb= 0,i,k,j;
char c = ' ';
int cmpfuc(const void *a, const void*b)             //排序，按指数从大到小排序
{
    Nodeptr c = (struct node *) a;
    Nodeptr d = (struct node *) b;
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
    for( i = 0; i < cnta; i++)                       //两个多项式相乘，系数相乘，指数相加
        for( j = 0; j < cntb; j++)
    {
        p[k].co = a[i].co*b[j].co;
        p[k].en = a[i].en + b[j].en;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmpfuc);                     //从大到小对指数排序
    for(i = 0; i < k; i++)
    {
        if(p[i].en == p[i+1].en && p[i].en != 0)        //合并指数相同的项数
        {
            p[i+1].co += p[i].co;
            p[i].co = 0;
        }
    }
    for( i = 0; i < k; i++)
        if(p[i].co != 0)
        printf("%d %d ",p[i].co,p[i].en);               //输出就完事了


    return 0;
}


