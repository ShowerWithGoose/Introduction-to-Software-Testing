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
            if (item <= q->data)
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
    int height = 0;
    preorder(root, height); // @@ [The height of the root should be 1, but passing 0 and incrementing at the start of preorder makes root height 1 only if counted correctly. However, the real issue is that the BST insertion logic incorrectly places equal values to the left instead of the right as per problem description ("right child is greater than or equal"). This causes incorrect tree structure and missing leaf node 87 while adding an extra 100 as leaf. Also, the height calculation during traversal is correct in approach but the tree structure is wrong due to insertion condition.]
    return 0;
}