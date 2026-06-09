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
int get_Depth(BTNodeptr x, int b) 
{
    BTNodeptr m = x;
    int n = 1;
    if (m->data == b) // @@ [Logic error: When root matches, depth should be 1, but here it increments to 2 and moves to right child, which is incorrect. Also, if root has no right child, it will later return -1.]
    {
        n++; // @@ [Part of the incorrect logic for root match.]
        m = m->right; // @@ [Incorrectly moving to right child when root matches; should handle root case properly.]
    }//跟头节点一样直接去右树
    if (m == NULL) // @@ [Logic error: This check is after possibly moving to right child. If root's value matched and root has no right child, m becomes NULL and incorrectly returns -1. Also, if root's value did not match, m is still root (non-NULL) and this condition is skipped.]
    {
        return -1;
    }
    else
    {
        while (m->data != b) // @@ [Logic error: No null check inside loop. If the value b is not present in the tree, the loop may access m->data when m is NULL, causing segmentation fault. Also, for a valid node, the loop should start from root, not after a potential move.]
        {
            if (m->data < b)
            {
                m = m->right; // @@ [Potential null pointer if right child is NULL.]
            }
            else
            {
                m = m->left; // @@ [Potential null pointer if left child is NULL.]
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
            int depth = get_Depth(root, a); // @@ [Logic error: Uses value-based search to compute depth. This fails for duplicate values as it may find the wrong node. Also, it assumes all nodes have unique keys. Should use the stored depth from insertion or compute depth via recursion with node reference.]
            printf("%d %d\n", a, depth);
        }
    }
}
void  postorder(BTNodeptr t)
{
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        VISIT(t);       /* 访问T指结点  */ // @@ [Order error: The problem requires left-to-right order (inorder traversal). Postorder outputs left, right, then node, which may not preserve the required leaf order if the tree contains duplicate values or specific structures. Should be inorder: left, VISIT, right.]
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