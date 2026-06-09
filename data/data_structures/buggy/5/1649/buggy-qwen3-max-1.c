#include<stdio.h>
#include<stdlib.h>
struct number{
    int a;//系数 
    int b;//指数 
};
typedef struct number num;
num x[1000]={},y[1000]={},z[1000]={};
int cmp(const void*a,const void*b);
int main()
{
    int n1=0,n2=0;
    char ch;
    for(n1=0;;n1++)
    {
        scanf("%d%d%c", &x[n1].a,&x[n1].b,&ch);
        if(ch=='\n')
        break;
    }
    for(n2=0;;n2++)
    {
        scanf("%d%d%c", &y[n1].a,&y[n1].b,&ch); // @@ [The index should be n2, not n1. This causes reading input into the wrong array location, leading to incorrect polynomial data.]
        if(ch=='\n')
        break;
    }
    int k=0;
    for(int i=0;i<=n1;i++) // @@ [Loop should run while i < n1, not i <= n1. The variable n1 is the count of terms, so valid indices are 0 to n1-1. Including n1 accesses uninitialized memory.]
    {
        for(int j=0;j<=n2;j++) // @@ [Same issue: loop should be j < n2, not j <= n2. This leads to accessing y[n2], which is beyond the valid input range.]
        {
            z[k].a=x[i].a*y[j].a;
            z[k].b=x[i].b+y[j].b;
            k++;
        }
    }
    qsort(z,k,sizeof(num),cmp);
    for(int i=0;i<k-1;i++)
    {
        if(z[i].b==z[i+1].b)
        {
            z[i+1].a+=z[i].a;
            z[i].a=0;
        }
    }
    qsort(z,k,sizeof(num),cmp);
    for(int i=0;i<k;i++)
    {
        if(z[i].a==0)
        continue;
        else
        printf("%d %d ", z[i].a,z[i].b);
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    num *pa=(num*)a;
    num *pb=(num*)b;
    return pb->b-pa->b;
}