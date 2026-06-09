/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的不良后果 */
#include<stdio.h>
#include<stdlib.h>
struct mul{
    int a;
    int b;
};
int cmp(const void* p,const void* q)
{
    return ((struct mul*)q)->b-((struct mul*)p)->b;
}
int main()
{
    struct mul fir[205];
    struct mul sec[205];
    struct mul ret1[205];
    struct mul ret2[205];
    int i=0,j=0,k,ii,n=0,op=1,oop=0,m=0;
    char c;
    while(scanf("%d%d%c",&fir[i].a,&fir[i].b,&c))
    {
        if(c=='\n')
        {
            break;
        }
        else
        {
            i++;
        }
    }
    while(scanf("%d%d%c",&sec[j].a,&sec[j].b,&c))
    {
        if(c=='\n')
        {
            break;
        }
        else
        {
            j++;
        }
    }
    for(k=0;k<=i;k++) // @@ 循环条件错误：当i=0时，循环会执行两次（k=0和k=1），但fir[1]未初始化，导致读取垃圾值
    {
        for(ii=0;ii<=j;ii++) // @@ 循环条件错误：当j=0时，循环会执行两次（ii=0和ii=1），但sec[1]未初始化，导致读取垃圾值
        {
            ret1[n].a=fir[k].a*sec[ii].a;
            ret1[n].b=fir[k].b+sec[ii].b;
            n++;
        }
    }
    qsort(ret1,n-1,sizeof(struct mul),cmp); // @@ 排序范围错误：应为n个元素，但n-1漏掉了最后一个元素
    /*for(k=0;k<n;k++)
    {
        printf("%d %d ",ret1[k].a,ret1[k].b);
    }*/
    for(k=0;k<n;k++)
    {
        ret2[k].a=0;
    }
    ret2[0].a=ret1[0].a;
    ret2[0].b=ret1[0].b;
    ii=1;
    for(k=0;k<n;k++) // @@ 合并逻辑错误：循环条件k<n导致访问ret1[n]越界，且合并算法无法正确处理所有情况
    {
        if(ret1[k].b!=ret1[k+1].b) // @@ 当k=n-1时，ret1[k+1]即ret1[n]越界访问
        {
            oop++;
        }
        else
        {
            op++;
        }
        if((oop==2)||((oop==1)&&(k+1==n))) // @@ 条件判断逻辑错误：无法正确合并相同指数的项
        {
            if(k+1==n)
            {
                ret2[ii].a=ret1[n-1].a;
                ret2[ii].b=ret1[n-1].b;
            }
            else
            {
              for(i=1;i<=op;i++)
              {
                ret2[ii].a=ret2[ii].a+ret1[k-op+i].a;
              }
              ret2[ii].b=ret1[k].b;
              ii++;
              k--;
              op=1;
              oop=0;
            }
        }
    }
    while(ret2[m].a!=0) // @@ 输出条件错误：系数可能为0但应输出，且未处理系数为0的项应跳过
    {
        printf("%d %d ",ret2[m].a,ret2[m].b);
        m++;
    }
    return 0;
}