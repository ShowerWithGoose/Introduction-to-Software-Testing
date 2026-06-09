#include<stdio.h>
#include<string.h>
#include<math.h>
int arr[10]={1,2,3,4,5,6,7,8,9,10};

void change1(int a[],int b,int c,int d)
{
    int temp=a[b],i=b+1;
    int j=0;
    a[b]=a[c];
    a[c]=temp;
    for(;i<=d;i++)
    {
        for(j=i;j<=d;j++)
        {
            if(a[i]>a[i+1])   @@ // Error: uses incorrect index (should be j, not i) and risks out-of-bounds access when i == d
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }    
    }

}

void change2(int a[],int b,int c,int d)   @@ // Error: does not undo the swap of a[b] and a[c], so the array state is not correctly restored for subsequent iterations
{
    int i=b+1;
    int j=0,temp=0;
    for(;i<=d;i++)
    {
        for(j=i;j<=d;j++)
        {
            if(a[i]>a[i+1])   @@ // Error: same incorrect index and out-of-bounds issue as in change1
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }    
    }
}

void function(int x[], int p, int q)
{
    int i=0,j=0;
    if(p==q)
    {
        for(;i<q+1;i++)
        {
            printf("%d",x[i]);   @@ // Error: missing spaces between numbers; should be "%d " to match output format
        }
        printf("\n");
    }
    else
    {
        for(j=p;j<=q;j++)
        {
            change1(x,p,j,q);
            function(x,p+1,q);
            change2(x,p,j,q);
        }
    }
}


int main()
{
    
    int n;
    scanf("%d",&n);
    function(arr,0,n-1);
    return 0;
}