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
    while(scanf("%d%d",&factor_b[i],&power_b[i])!=EOF)
    i++; // @@ [This loop does not correctly detect end of second line; it reads until EOF instead of stopping at newline, causing incorrect input parsing]
    len_b = i;

    // for(i=0;i<len_a;i++)
    // printf("%d %d -",factor_a[i],power_a[i]);printf("\n");
    // for(i=0;i<len_b;i++)
    // printf("%d %d -",factor_b[i],power_b[i]);
    for(i=0;i<(len_a*len_b);i++)
    {
        power_ab[i] = factor_a[i/len_b] + factor_b[i%len_b]; // @@ [Incorrect: should be power_a[i/len_b] + power_b[i%len_b], not factor_a and factor_b]
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
                factor_c[k] += factor_a[i]*factor_b[j]; // @@ [factor_c[k] is used uninitialized; should be initialized to 0 before accumulation]
            }
        }
    }

    for(i=0;i<len_c;i++)
    {
        printf("%d %d ",factor_c,power_c); // @@ [Should be factor_c[i] and power_c[i], not the array names without index]
    }
    return 0;
}