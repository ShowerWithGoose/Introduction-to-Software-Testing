#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n;
void func(int o)
{
    if(o==1)
    {
        for(int k=0;k<n;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(int l=n-o;l<n;l++) // @@ This loop generates permutations but not in lexicographic order; the algorithm does not produce the required sorted output.
        {
            int mid;
            mid=a[l];
            a[l]=a[n-o];
            a[n-o]=mid;
            func(o-1); // @@ This recursive call, combined with the loop, creates permutations in an order that is not lexicographic.
            mid=a[l];
            a[l]=a[n-o];
            a[n-o]=mid;
        }
    }
}
int main()
{
    scanf("%d",&n);
    func(n);
    return 0;
}