#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000

typedef struct node
{
    int data;      //节点数据
    int depth;     //节点深度
    int flag_leaf; //标记
} Tree;
Tree tree[maxn + 10];
int deep = 0;

void build(int pos, int temp) // pos为节点位置序号，从上到下，从左到右编号，根节点为1
{
    deep++;                   //记录当前操作的深度
    if (tree[pos].data == -1) //如果这个结点之前没存数据，就存在这里
    {
        tree[pos].data = temp;
        tree[pos].depth = deep; //该节点深度即为当前操作深度
    }
    else if (temp < tree[pos].data) //分左右
    {
        tree[pos].flag_leaf = 0; //说明有孩子，标记
        build(2 * pos, temp);    //去左边找 2*pos为pos的左孩子
    }
    else if (temp >= tree[pos].data) //分左右
    {
        tree[pos].flag_leaf = 0;  //说明有孩子，标记
        build(2 * pos + 1, temp); //去右边找 2*pos+1为pos的右孩子
    }
}

void LTR(int pos) // Left_to_Right函数，查找并输出叶节点
{
    if (tree[pos].data != -1) //如果这一节点数据非空
    {
        LTR(2 * pos); //去右边找 2*pos为pos的左孩子

        // Left_to_Right函数最核心判断
        if (tree[2 * pos].data == -1 && tree[2 * pos + 1].data == -1) //如果左孩子这一节点没有子节点
        {
            printf("%d %d\n", tree[pos].data, tree[pos].depth); //输出该左孩子节点
        }

        LTR(2 * pos + 1); //去右边找 2*pos+1为pos的右孩子
    }
}
// Left_to_Right函数将按层数加深自行递归，直至找到空节点为止
int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < maxn + 9; i++) //初始化
    {
        tree[i].data = -1;
        tree[i].depth = 0;
        tree[i].flag_leaf = 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        deep = 0; //每次重置deep为0
        build(1, temp);
    }
    LTR(1);
    return 0;
}

