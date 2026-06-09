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
    qsort(num+start,end-start+1,sizeof(int),cmp); // @@ This line sorts the entire segment before generating permutations, which disrupts the lexicographic order and causes duplicate or missing permutations. In the reference program, sorting is done inside the loop after each swap to maintain order.
    for (int i=start;i<=end;i++)
    {
        swap(&num[start],&num[i]);
        f(num,start+1,end);
        swap(&num[start],&num[i]); // @@ This swap back restores the array, but combined with the initial sort, it fails to produce all permutations in lexicographic order. The reference program uses qsort after each swap to reorder the remaining elements, ensuring correct generation.
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