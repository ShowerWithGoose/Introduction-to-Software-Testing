#include<stdio.h>
#include<stdlib.h>
int flag;

typedef struct Node
{
    int val; 
    int deep;
    struct Node *link[2];
} Node;

Node *creatTree()
{   
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = 0;
    p->deep = 1;
    p->link[0] = p->link[1] = NULL;
    return p;
}

Node *creatNode(int val, int deep)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->deep = deep;
    p->link[0] = p->link[1] = NULL;
    return p;
}

void insert(Node *tree, int val)
{
    Node *p = tree;
    if(flag == 1)
        return ;
    else if(p == NULL)//当延某一条路径抵达树的尽头且未能成功插入时，则不改变flag的状态直接返回
        return ;
    else if(val < p->val&&p->link[0] == NULL)//val尚未找到合适的插入位置且val小于该节点的val且该节点的左子树为空，则在该节点的左子树位置插入
    {
        p->link[0] = creatNode(val, tree->deep + 1);
        flag = 1;
        return ;
    }
    else if(val >= p->val&&p->link[1] == NULL)//flag尚未找到合适的插入位置val大于等于该节点的val且该节点的右子树为空，则则在该节点的右子树位置插入
    {
        p->link[1] = creatNode(val, p->deep + 1);
        flag = 1;
        return ;
    }
    else //如果该节点不可插入则继续递归寻找合适的插入点
    {
        if(val < p->val)
            insert(p->link[0], val);
        else
            insert(p->link[1], val);
        return ;
    }
}

void output(Node *tree)
{
    Node *p = tree;
    if(p == NULL)//p为空，则返回上层节点
        return ;
    else if(p->link[0] == NULL&&p->link[1] == NULL)//p为叶节点，则输出
    {
        printf("%d %d\n", p->val, p->deep);
        return ;
    }
    output(p->link[0]);
    output(p->link[1]);
    return ;
}


int main()
{
    int n, val;
    Node *tree = creatTree();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        flag = 0;
        if(i == 0)
        {
            tree->val = val;
        }
        else
            insert(tree, val);
    }
    output(tree);
    return 0;
}
