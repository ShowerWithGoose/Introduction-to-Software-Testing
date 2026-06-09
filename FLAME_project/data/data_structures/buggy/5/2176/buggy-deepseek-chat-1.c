#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>

typedef struct item
{
    int factor;
    int power;
    struct item * link;
}item;//次幂从大到小连接
int factor_a[100];
int factor_b[100];
int power_a[100];
int power_b[100];
int power_ab[10000];
int power_c[10000];
int factor_c[10000];

int cmp(const void * p1,const void * p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    char c = 0;
    int i=0,j,len_a,len_b;//len 为数据组数
    //读数据
    while(c!='\n')
    {
        scanf("%d%d",&factor_a[i],&power_a[i]);
        i++;
        c = getchar();
    }
    len_a = i;
    i = 0;
    while(scanf("%d%d",&factor_b[i],&power_b[i])!=EOF) // @@ 错误：第二个多项式的读取条件应为遇到换行符停止，而不是EOF，因为输入只有一行，EOF会导致读取错误或无限循环
    i++;
    len_b = i;

    // for(i=0;i<len_a;i++)
    // printf("%d %d -",factor_a[i],power_a[i]);printf("\n");
    // for(i=0;i<len_b;i++)
    // printf("%d %d -",factor_b[i],power_b[i]);
    for(i=0;i<(len_a*len_b);i++)
    {
        power_ab[i] = factor_a[i/len_b] + factor_b[i%len_b]; // @@ 错误：这里错误地将系数相加，应该是指数相加，即 power_a[i/len_b] + power_b[i%len_b]
    }
    qsort(power_ab,len_a*len_b,sizeof(int),cmp);
    j=0;
    power_c[0] = power_ab[0];
    for(i=0;i<len_a*len_b;i++)
    {
        if(power_ab[i]!=power_c[j])
        power_c[++j] = power_ab[i];
    }
    int len_c = j+1,k;

    for(k=0;k<len_c;k++)
    {
        for(i=0;i<len_a;i++)
        {
            for(j=0;j<len_b;j++)
            {
                if(power_c[k]==power_a[i]+power_b[j])
                factor_c[k] += factor_a[i]*factor_b[j];
            }
        }
    }

    for(i=0;i<len_c;i++)
    {
        printf("%d %d ",factor_c,power_c); // @@ 错误：输出时缺少数组索引，应为 factor_c[i] 和 power_c[i]
    }
    return 0;
}