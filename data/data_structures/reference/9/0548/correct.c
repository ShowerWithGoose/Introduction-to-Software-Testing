#include <stdio.h>
#include<math.h>
#include <string.h>
#include <stdlib.h>
typedef struct qishizhongzhi
{
    int qishix,qishiy,jieshux,jieshuy;
    int num;
}
qishizhongzhi[150];



int f(const void *a, const void *b)
{
    struct qishizhongzhi *c = (qishizhongzhi *)a;
    struct qishizhongzhi *d = (qishizhongzhi *)b;
    if(c->qishix!=d->qishix)
        return d->qishix - c->qishix;
    else return d->qishiy - c->qishiy;
}
int main()
{
    struct  qishizhongzhi qishizhongzhi[150];
    int n;
    scanf("%d",&n);
    int i,j;
    for(i = 0; i < n; i++)
       { scanf("%d%d%d%d",&qishizhongzhi[i].qishix,&qishizhongzhi[i].qishiy,&qishizhongzhi[i].jieshux,&qishizhongzhi[i].jieshuy);
       qishizhongzhi[i].num = 1;}

    qsort(qishizhongzhi,n,sizeof(qishizhongzhi[0]),f);


    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n-1; j++)
        {
            if(qishizhongzhi[i].qishix==qishizhongzhi[j+1].jieshux && qishizhongzhi[i].qishiy == qishizhongzhi[j+1].jieshuy)
            {
                qishizhongzhi[j+1].num += qishizhongzhi[i].num;
            }
        }
    }
    int max = -1; int flag = 0;
    for(i = 0; i < n; i++)
    {
        if(qishizhongzhi[i].num > max)
            max = qishizhongzhi[i].num,flag = i;
    }
    printf("%d %d %d",max,qishizhongzhi[flag].qishix,qishizhongzhi[flag].qishiy);
    return 0;
}

