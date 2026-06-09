#define   _CRT_SECURE_NO_WARNINGS  1
#define MAXNUM 1000
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int num[MAXNUM];
typedef int Datatype;
struct node {
    Datatype data;
    struct node* left, * right;
};
typedef struct node BTNode, * BTNodeptr;
BTNodeptr  root = NULL;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
int a;
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if (p == NULL) 
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item);
    else if (item >= p->data)
        p->right = insertBST(p->right, item);
    return p;
}
//int get_Depth(BTNodeptr t, int a)
//{
//    static int count = 1;
//    if (t == NULL)
//    {
//        return 0;
//    }
//    else if (t->data == a)
//    {
//        return count;
//    }
//    else
//    {
//        count++;
//        int flag = get_Depth(t->left,a);
//        if (flag != 0)
//        {
//            return count;
//        }
//        else
//        {
//            count -= 1;
//            get_Depth(t->right, a);
//            return count;
//        }
//    }
//}
int get_Depth(BTNodeptr x, int b)  // @@ The function logic for calculating depth is fundamentally flawed. It assumes the target node is not the root or handles the root incorrectly, and uses a search-like approach rather than a recursive depth calculation from the root. For a single node tree (root is leaf), it returns -1 instead of 1.
{
    BTNodeptr m = x;
    int n = 1;
    if (m->data == b)
    {
        n++;
        m = m->right;
    }//跟头节点一样直接去右树
    if (m == NULL)
    {
        return -1;
    }
    else
    {
        while (m->data != b)
        {
            if (m->data < b)
            {
                m = m->right;
            }
            else
            {
                m = m->left;
            }
            n++;
        }
        return n;
    }
}
void VISIT(BTNodeptr t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)//题目只让输出叶节点，显然根节点不满足if里的条件，直接不管
        {
            a = t->data;
            int depth = get_Depth(root, a);
            printf("%d %d\n", a, depth);
        }
    }
}
void  postorder(BTNodeptr t)
{
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        VISIT(t);       /* 访问T指结点  */
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int i, item;
    for (i = 0; i < n; i++) { //构造一个有n个元素的BST树
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    postorder(root);
    return 0;
}
//如果根没有右子树或左子树