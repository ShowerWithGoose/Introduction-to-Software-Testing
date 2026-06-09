#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sort(int l,int r,int a[],int b[],int c[],int d[])
{
    int mid=a[(l+r)/2];
    int i=l,j=r;
    int tmp,tmp1,tmp2,tmp3;
    do
    {
        while(a[i]<mid)
        i++;
        while(a[j]>mid)
        j--;
        if(i<=j)
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            tmp1=b[i];
            b[i]=b[j];
            b[j]=tmp1;
            tmp2=c[i];
            c[i]=c[j];
            c[j]=tmp2;
            tmp3=d[i];
            d[i]=d[j];
            d[j]=tmp3;
            i++;
            j++; // @@ Error: should be j-- to move the right pointer inward. Using j++ causes out-of-bounds and incorrect partitioning.
        }
    }
    while(i<=j);
            if(l<j)
            sort(l,j,a,b,c,d);
            if(i<r)
            
                sort(i,r,a,b,c,d);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[105],b[105],a1[105],b1[105];
    int count[105]; // @@ Error: array not initialized. Should be `int count[105] = {0};` to avoid garbage values.
    int a2=0,b2=0;
    int max=0;
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&a1[i],&b1[i]);
        
    }
    sort(0,n-1,a,b,a1,b1);
    for(int i=0;i<n;i++)
    {
        a2=a1[i];
        b2=b1[i];
        for(int t=i+1;t<n;t++)
        {
            if(a[t]==a2&&b[t]==b2)
            {
                count[i]++; // @@ Error: should accumulate counts from later segments, e.g., count[i] += 1 + count[t]; and also mark count[t] as used. Current logic undercounts chain length.
                a2=a1[t];
                 b2=b1[t];
            }
        }
    }
     t=0;
    for(int i=0;i<n;i++)

{
if(count[i]>max)
{
max=count[i];
t=i;}
    }
    printf("%d %d %d\n",max+1,a[t],b[t]);
    return 0;
}