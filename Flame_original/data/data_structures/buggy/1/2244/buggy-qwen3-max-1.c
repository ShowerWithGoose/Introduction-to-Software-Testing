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
            if(a[i]>a[i+1])  // @@ [Array index out of bounds: when i == d, a[i+1] accesses a[d+1], which is beyond the valid range [0, d]]
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
            if(a[i]>a[i+1])  // @@ [Array index out of bounds: when i == d, a[i+1] accesses a[d+1], which is beyond the valid range [0, d]]
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
            printf("%d",x[i]);  // @@ [Missing space between numbers as required by output format; should print "%d " instead]
        }
        printf("\n");
    }
    else
    {
        for(j=p;j<=q;j++)
        {
            change1(x,p,j,q);
            function(x,p+1,q);
            change2(x,p,j,q);  // @@ [Incorrect restoration logic: change2 does not undo the swap done in change1, leading to incorrect permutations and missing lexicographical order]
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