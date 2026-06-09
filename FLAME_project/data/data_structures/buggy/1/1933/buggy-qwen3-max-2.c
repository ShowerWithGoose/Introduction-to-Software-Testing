#include <stdio.h>
#include <stdlib.h>
int num[10001];
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}//直接通过改变地址储存的值来交换

int cmp(const void *a, const void *b) {
    if(*(int *)a - *(int *)b>0)
        return 1;
    else if(*(int *)a-*(int *)b<0)
        return -1;
    return 0;
}
//递归
void f(int num[], int start, int end)
{
    if (start==end)
    {
        for (int i=0;i<=end;i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }

    //对当前排列进行排序
    qsort(num+start,end-start+1,sizeof(int),cmp);
    for (int i=start;i<=end;i++)
    {
        swap(&num[start],&num[i]);
        f(num,start+1,end);
        swap(&num[start],&num[i]); // @@ [This backtracking swap restores the original order, which interferes with the lexicographical ordering requirement. The algorithm should not restore the array after recursion because it relies on generating permutations in sorted order by fixing elements and recursing on a sorted suffix. Restoring breaks the sorted state needed for correct lexicographic output.]
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++)
    {
        num[i]=i+1;
    }
    f(num,0,N-1);
    return 0;
}