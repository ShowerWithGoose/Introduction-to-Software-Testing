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
        scanf("%d%d%c", &y[n1].a,&y[n1].b,&ch); // @@ [Incorrect index: should be y[n2], not y[n1]]
        if(ch=='\n')
        break;
    }
    int k=0;
    for(int i=0;i<=n1;i++) // @@ [Loop bound error: should be i < n1, since n1 is the count of terms read (0-based), but loop includes n1 which is out-of-bound]
    {
        for(int j=0;j<=n2;j++) // @@ [Loop bound error: should be j < n2 for same reason as above]
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