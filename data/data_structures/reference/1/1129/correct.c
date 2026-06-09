#include <stdio.h>
#include <stdlib.h>
void f5(int m, int n, int a[], int temp[]);
int a[20], temp[20], n;
int main()
{
    scanf("%d", &n);   //输入n
    f5(0, n, a, temp); //传入：“第0层”，“深度搜索层数”，“记答案”，“
    getchar();
    return 0;
}
void f5(int m, int n, int a[], int temp[])
{
    int i;
    if (m >= n) //层数够了，输出一种排列
    {
        for (i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[i]);
    }
    else //层数不够，再搜索一个
    {
        for (i = 0; i < n; i++) //找层数
        {
            if (!temp[i]) // temp是1-10的一个表，temp为0表示数字没用过
            {
                temp[i] = 1;           //用了奥
                a[m] = i + 1;          // i从0开始，所以要加1
                f5(m + 1, n, a, temp); //搜下一个
                temp[i] = 0;           //退回上一层
            }
        }
    }
}

