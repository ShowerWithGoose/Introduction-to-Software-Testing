#include<stdio.h>/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdlib.h>
long long f(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return n*f(n-1);
}
int swap(int arr[], int a, int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void perm(int a[], int begin, int n)
{
    if(begin==n)
    {
        for(int i=0;i<=n;i++) // @@ [Loop condition should be i < n, not i <= n. This causes out-of-bounds access since valid indices are 0 to n-1.]
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int j = begin;j<=n;j++) // @@ [Loop condition should be j <= n only if n is the last index. But in main, perm is called with n-1 as 'n', so this loop should run j from begin to n (inclusive), which is correct given the call. However, combined with the previous error, this may cause confusion. The real issue is the print loop using <= n.]
        {
            swap(a, begin, j);
            perm(a, begin+1, n);
            swap(a, begin, j);
        }
    }
}
int main()
{
    
    int n, i;
    int* a;
    scanf("%d", &n);
    a=(int*)calloc(n, sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        
    }
    perm(a, 0, n-1);
    return 0;
}