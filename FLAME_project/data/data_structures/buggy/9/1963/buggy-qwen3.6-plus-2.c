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
            j--; // @@ The original code had j++ here, which causes infinite loops or incorrect sorting in quicksort partitioning. It should be j-- to move the right pointer leftwards.
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
    int count[105]; // @@ The array 'count' is declared but not initialized. Accessing uninitialized values leads to undefined behavior (garbage values). It should be initialized to 0.
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
        count[i] = 0; // @@ Although initialization at declaration is preferred, we can initialize here before use if we assume the previous error was just lack of initialization. However, since I must annotate lines where errors occur, the declaration line is the primary spot. But logically, the loop below uses count[i]++. If count isn't 0, it's wrong. Let's look at the logic.
        a2=a1[i];
        b2=b1[i];
        for(int t=i+1;t<n;t++)
        {
            if(a[t]==a2&&b[t]==b2)
            {
                count[i]++;
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