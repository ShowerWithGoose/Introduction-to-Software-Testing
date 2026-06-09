#include<stdio.h>
int n;
int arr[15] = { 0 };
int state[15] = { 0 };//状态数组，表示某个数是否已经被选取，1表示被选取，0表示未被选取
void DFS(int x)
{
    int i;
    if (x > n)
    {
        for (i = 1; i <= n; i++)
            printf("%d", arr[i]); // @@ [Missing space between numbers as required by output format; should print "%d " instead of "%d"]
        printf("\n");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (state[i] == 0)//某个数还没有被选取
            {
                state[i] = 1;//表示已经被选取
                arr[x] = i;//让这个数放在第x个位置
                DFS(x + 1);//对下一个位置进行递归
                //恢复原始状态
                state[i] = 0;
                arr[x] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    DFS(1);
    return 0;
}