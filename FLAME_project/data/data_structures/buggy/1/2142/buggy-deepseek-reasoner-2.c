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
int swap(int arr[], int a, int b) // @@ [函数返回值类型应为void，缺少return语句，未定义行为]
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void perm(int a[], int begin, int n)
{
    if(begin==n)
    {
        for(int i=0;i<=n;i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int j = begin;j<=n;j++)
        {
            swap(a, begin, j); // @@ [缺少对begin+1到n部分进行排序，以保证后续递归的字典序]
            perm(a, begin+1, n);
            swap(a, begin, j); // @@ [缺少对begin+1到n部分进行排序恢复，以保持数组状态一致]
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