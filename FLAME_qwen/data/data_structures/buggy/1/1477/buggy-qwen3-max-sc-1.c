#include <stdio.h>
#include <stdlib.h>

int finish[10]; // 用于标记数字是否已经被使用过的数组
int res[10]; // 存储当前排列的数组
int n; // 输入的数字范围

// 深度优先搜索函数，用于生成排列
void dfs(int index)
{
    if (index == n) // 如果已经填满了排列
    {
        // 输出当前排列
        for (int i = 0; i < n; i++)
        {
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        // 遍历可能的数字
        for (int i = 1; i <= n; i++)
        {
            if (!finish[i]) // 如果当前数字未被使用
            {
                res[cnt] = i; // 将当前数字加入排列中 @@ [变量 'cnt' 未定义，应为 'index']
                finish[i] = 1; // 标记当前数字为已使用
                dfs(index + 1); // 递归填充下一个位置
                finish[i] = 0; // 回溯，将当前数字重新标记为未使用
            }
        }
    }
}

int main()
{
    scanf("%d", &n); // 输入数字范围

    dfs(0); // 调用深度优先搜索函数生成排列

    return 0;
}