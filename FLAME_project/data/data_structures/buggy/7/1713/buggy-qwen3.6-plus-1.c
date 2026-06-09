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
            if (item <= q->data) // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts equal items to the left, which contradicts the requirement. It should be item < q->data for left.
            {
                if (q->left == NULL)
                {
                    q->left = p;
                    break;
                }
                else
                    q = q->left;
            }
            else if (item > q->data) // @@ Consequently, this branch handles items greater than root. Since the previous condition was wrong, this one is also effectively handling the wrong set relative to the "greater than or equal" rule for right children. It should be item >= q->data.
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
        preorder(t->left,height);
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
    int height = 0; // @@ The problem states the height of the root node is 1. The preorder function increments height before processing the node. If we pass 0, the root becomes 1, which is correct. However, looking at the reference program, it stores height in the node. Here, passing 0 is actually correct for the logic inside preorder (height++ makes root 1). So this line is likely fine logically regarding the start value, but let's re-read carefully. "height of the root node is 1". preorder(t, 0) -> height becomes 1. Correct.
    preorder(root, height);
    return 0;
}