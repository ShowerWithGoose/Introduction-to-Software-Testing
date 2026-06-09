#include<stdio.h>

int a,b,m,n,x,p[1005],t;

void huan(int a,int b);
void pai(int m,int n);

int main()
{
    int j;
    scanf("%d",&x);
    for(j=1;j<=x;j++)
    {
        p[j]=j;
    }
    
    pai(1,x);
    
    return 0;
}

void pai(int m,int n)
{
    int k,i;
    if(m==n)
    {
        for(k=1;k<=x;k++)
        {
            printf("%d ",p[k]);
        }
        printf("\n");
    }
    else
    {
        for(i=m;i<=n;i++) // @@ This loop uses swapping to generate permutations, but the resulting order is not lexicographic. The standard swap-backtracking algorithm produces permutations in a different order (often called "algorithmic order"). For lexicographic order, a different approach (like the reference program's method) is required.
        {
            huan(m,i); // @@ Swapping elements disrupts the sorted order needed for lexicographic output. After swapping, the recursive calls produce permutations that are not in lexicographic sequence.
            pai(m+1,n);
            huan(m,i); // @@ Swapping back is correct for backtracking, but the overall algorithm still does not yield lexicographic order.
        }    
    }
}

void huan(int a,int b)
{
    t=p[a];
    p[a]=p[b];
    p[b]=t;
}