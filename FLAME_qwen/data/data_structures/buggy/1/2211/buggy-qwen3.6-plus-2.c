#include <stdio.h>
void permutation(int m,int n);
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};

int main()
{
    int n;
    scanf("%d",&n);
    permutation(1,n);
    return 0;
}

//名称： 全排列
//参数： m:主函数取1； n:主函数取排列中最大数
//备注： m表示层数(纵向看)，一层一层推进
//      第m层，需要交换m与k，k：m~n的位置的数
void permutation(int m,int n){
    if (m==n)//到最后一位，输出
    {
        for (int i = 1; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d",a[n]);
        printf("\n");
    }  
    else for (int i = m; i <= n; i++)//m层，生成n-m+1次
    {
        int temp;
        temp = a[m]; // @@ Direct swap disrupts the relative order of the remaining elements, failing to generate permutations in lexicographical order as required.
        a[m] = a[i]; // @@ Direct swap disrupts the relative order of the remaining elements, failing to generate permutations in lexicographical order as required.
        a[i] = temp;//交换a[层数]与a[i],i从m到n // @@ Direct swap disrupts the relative order of the remaining elements, failing to generate permutations in lexicographical order as required.

        permutation(m+1,n);

        temp = a[m]; // @@ Backtracking swap also disrupts order; a shift/rotation method is needed to maintain lexicographical order.
        a[m] = a[i]; // @@ Backtracking swap also disrupts order; a shift/rotation method is needed to maintain lexicographical order.
        a[i] = temp;//换回来 // @@ Backtracking swap also disrupts order; a shift/rotation method is needed to maintain lexicographical order.
    }
}