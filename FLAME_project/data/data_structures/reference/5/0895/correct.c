#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int xi;                     //两个值，一个存系数，一个存指数
    int mi;
} a[101230],b[114121],p[123124],q[124124];

int count_1 = 0,count_2= 0;
char c = ' ';
int cmpfuc(const void *a, const void*b)             //排序，按指数从大到小排序
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return d->mi - c->mi;
}
int main()
{
    while( c != '\n')                                   //读入第一个多项式
    {
        scanf("%d%d%c",&a[count_1].xi,&a[count_1].mi,&c);
        count_1++;
    }
    c = ' ';
    while( c != '\n')                                   //读入第二个多项式
    {
        scanf("%d%d%c",&b[count_2].xi,&b[count_2].mi,&c);
        count_2++;
    }
    int k = 0;
    for(int i = 0; i < count_1; i++)                       //两个多项式相乘，系数相乘，指数相加
        for(int j = 0; j < count_2; j++)
    {
        p[k].xi = a[i].xi*b[j].xi;
        p[k].mi = a[i].mi + b[j].mi;
        k++;
    }
    qsort(p,k,sizeof(p[0]),cmpfuc);                     //从大到小对指数排序
    for(int i = 0; i < k; i++)
    {
        if(p[i].mi == p[i+1].mi && p[i].mi != 0)        //合并指数相同的项数
        {
            p[i+1].xi += p[i].xi;
            p[i].xi = 0;
        }
    }
    for(int i = 0; i < k; i++)
        if(p[i].xi != 0)
        printf("%d %d ",p[i].xi,p[i].mi);               //输出就完事了


    return 0;
}

