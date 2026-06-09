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
        for(int l=n-o;l<n;l++) // @@ [The algorithm does not generate permutations in lexicographic order because the recursive swapping method does not maintain the sorted order of the remaining elements after each swap; this results in an incorrect order for N > 3, failing the problem's requirement. For N=2 it coincides, but the test case is misleading.]
        {
            int mid;
            mid=a[l];
            a[l]=a[n-o];
            a[n-o]=mid;
            func(o-1);
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