#include <stdio.h>
int num[10], used[10];
int write = 0;

void perm(int step, int n)
{
    int i;
    if (step == n)
    {
        for (i = 0; i < n; i++)
            printf("%d ", num[i]);
        printf("\n");
    }
    else
        for (i = 0; i < n; i++)
            if (used[i] == 0)
            {
                num[write] = i + 1; //按从小到大顺序写入num
                write++;            //写入位置后移一位
                used[i] = 1;
                perm(step + 1, n);
                write--; //复位
                used[i] = 0;
            }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        used[i] = 0;
    for (; i < 10; i++)
        used[i] = 2;
    perm(0, n);
    return 0;
}


