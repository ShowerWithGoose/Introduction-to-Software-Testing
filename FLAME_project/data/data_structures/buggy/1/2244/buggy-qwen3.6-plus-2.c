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
            if(a[i]>a[i+1]) // @@ [Index out of bounds: when j equals d, accessing a[i+1] (which is a[d+1]) reads beyond the intended subarray or array bounds. The inner loop condition should be j < d.]
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }    
    }

}

void change2(int a[],int b,int c,int d)
{
    int i=b+1;
    int j=0,temp=0;
    for(;i<=d;i++)
    {
        for(j=i;j<=d;j++)
        {
            if(a[i]>a[i+1]) // @@ [Index out of bounds: same error as in change1. Accessing a[i+1] when i can reach d causes out-of-bounds access. The inner loop condition should be j < d.]
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
            printf("%d",x[i]); // @@ [Formatting error: The problem requires integers to be separated by a space. This prints numbers consecutively (e.g., "12" instead of "1 2"). It should be printf("%d ", x[i]); or similar formatting with spaces.]
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