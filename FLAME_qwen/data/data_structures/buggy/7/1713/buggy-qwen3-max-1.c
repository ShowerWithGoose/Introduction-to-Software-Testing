#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node, *nodeptr;
nodeptr root = NULL; // root是一个全局变量
void insertBST(int item)
{
    nodeptr p, q;
    p = (nodeptr)malloc(sizeof(node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    if (root == NULL)
        root = p;
    else
    {
        q = root;
        while (1)
        {
            // 比较值的大小，小于向左，大于向右
            if (item <= q->data)  // @@ [The problem description specifies that left child values must be < root, and right child values >= root. This condition uses <= for the left, which incorrectly places equal values on the left instead of the right.]
            {
                if (q->left == NULL)
                {
                    q->left = p;
                    break;
                }
                else
                    q = q->left;
            }
            else if (item > q->data)
            {
                if (q->right == NULL)
                {
                    q->right = p;
                    break;
                }
                else
                    q = q->right;
            }
        }
    }
}
void preorder(nodeptr t,int height)
{
    if(t!=NULL)
    {
        height++;
        if(t->left==NULL&&t->right==NULL)
            printf("%d %d\n", t->data, height);
        preorder(t->left,height);  // @@ [The height is passed by value, so modifications in deeper recursive calls do not affect the current call's height. However, this is actually correct behavior for a preorder traversal that computes height per path. The real issue is in the insertion logic, not here. But note: the traversal order is preorder, but the problem requires outputting leaf nodes from left to right, which corresponds to inorder traversal of leaves. However, preorder traversal visits left subtree before right, so leaf output order may still be correct. The main bug remains in insertion condition.]
        preorder(t->right,height);
    }
}
int main()
{
    int n, a[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insertBST(a[i]);
    }
    int height = 0;
    preorder(root, height);
    return 0;
}