//
//  main.c
//  全排列
//
//  Created by  on 2022/3/12.
//

#include <stdio.h>
void Depth_First_Search(int *a, int *b, int n, int depth);
int a[11] = {0};
int b[11] = {0};
int main(int argc, const char * argv[])
{
    int n;
    scanf("%d",&n);
    Depth_First_Search(a, b, n, 1);
    return 0;
}
void Depth_First_Search(int *a, int *b, int n, int depth)
//深度优先遍历（树形），本质是通过递归和试错来列举出全排列。其中的深度depth代表着递归的层数,也就是目前所用数字的下标
//例如3的全排列，先选择1，再选择2，选择3，此时撤销3，同时撤销2，回到1的位置，再选择3，选择2，此时排列完全，撤回2，3，同时撤回1，回到选择2的情况，以此类推。
{
    int i;
    if (depth==n+1)//当递归层数超出输入的层数时，结束递归，直接输出结果。
    {
        for (i=1; i<=n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for (i=1; i<=n; i++)
    {
        if (b[i]==0)//bool数组，初始赋值为0，如果用到的话就改为1，在这个算法中用完了就撤销为0
        {
            b[i]=1;
            a[depth]=i;
            Depth_First_Search(a, b, n, depth+1);//递归
            b[i]=0;
        }
    }
}

