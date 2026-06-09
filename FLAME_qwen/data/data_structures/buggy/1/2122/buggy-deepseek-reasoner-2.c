#include <stdio.h>
int n, arr[10]={}, used[10]={}; // @@ 数组大小应为11，避免索引越界（N最大为10时arr[10]越界）
void arrange(int a);
int main()
{
    scanf("%d", &n);
    arrange(1);
    return 0;
}
void arrange(int a)
{
    if(a>n)
    {
        for (int i = 1; i <= n;i++)
        {
            printf("%d", arr[i]); // @@ 输出缺少空格，不符合题目要求的空格分隔格式
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 1; i <= n;i++)
        {
            if(used[i]==0)
            {
                arr[a] = i;
                used[i] = 1;
                arrange(a + 1);
                used[i] = 0;
            }
            
        }
    }
}