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
        scanf("%d%d%c", &y[n1].a,&y[n1].b,&ch); // @@ [Error: Using index n1 instead of n2 to store the second polynomial's terms, causing data corruption and overwriting]
        if(ch=='\n')
        break;
    }
    int k=0;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
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