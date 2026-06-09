#include <stdio.h>
#include <stdlib.h>
void Permutation(int m, int n, int arr[], int temp[]);
int arr[15],temp[15];
int main()
{
    int i,n;
    scanf("%d", &n);
    //需要将标识数组temp初始化为0（局部变量默认随机，可更换为全局变量，默认为0）
    Permutation(0, n, arr, temp);
    return 0;
}
void Permutation(int m, int n, int arr[], int temp[])
{
    int i;
    //递归到底层
    if(m >= n)
    {
        for (i = 0; i < n-1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[i]);
    }
    else
        for(i = 0; i < n; i++)
            if (temp[i] == 0)
            {
                temp[i] = 1;
                arr[m] = i + 1;//递归到下一层
                Permutation(m + 1, n, arr, temp);//保证递归后保持上一层的顺序
                temp[i] = 0;
            }
}


