// 1.深度优先搜索  回溯，递归实现
// 2.状态：path，depth，used, 

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int count;


void DFS(int n, int** ans, int * path, int depth, bool* used)
{
    if(depth == n)
    {
        ans[count] = (int*)malloc(sizeof(int) * n);

        memcpy(ans[count++], path, sizeof(int) * n);
        return ;
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == true)
        {
        continue;
        }

        path[depth] = i + 1;
        used[i] = true;

        DFS(n, ans, path, depth + 1, used);
        used[i] = false;
    }

    return ;
}


int main()
{
    int n = 0;
    int numSize = 1;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        numSize *= i;
    }
    
    int* path = (int*)malloc(sizeof(int) * n);
    int depth = 0;
    bool* used = (bool*)malloc(sizeof(bool) * n);

    for(int i=0; i < n; i++)
    {
        used[i] = false;
    }

    int** ans = (int**)malloc(sizeof(int*) * numSize);

    count = 0;

    DFS(n, ans, path, depth, used);
    

    for(int i = 0; i < numSize; i++)
    {
        for(int j = 0; j < n; j++)
        {
        printf("%d",ans[i][j]);
        if(j != n-1)
        {
            printf(" ");
        }
        }
        printf("\n");
    }
    
    return 0;
}
