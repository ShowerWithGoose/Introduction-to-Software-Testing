#include<stdio.h>
int a[10], book[100], n;
void dfs(int step)
{
    int i;
    if (step == n + 1)  //如果站在n+1个盒子面前，则表示前n个盒子已经放好了扑克牌
    {   //输出前n个盒子中扑克牌的编号
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (book[i] == 0)  //判断扑克牌i是否还在手上
        {
            a[step] = i;  //将i号扑克牌放入第step个盒子中
            book[i] = 1;  //将book[i]设为1，表示i号扑克牌已经不在手上
            dfs(step + 1);  //函数递归
            book[i] = 0;  //一定要将刚才尝试的扑克牌收回，才能进行下一步尝试
        }
    }
    return;
}

int main()
{
    scanf("%d", &n); 
    dfs(1); 
}
