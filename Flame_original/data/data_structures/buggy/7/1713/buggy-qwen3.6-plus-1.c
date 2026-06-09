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
            if (item <= q->data) // @@ The problem specifies left child < root and right child >= root. Using <= directs equal values to the left, violating the specification. It should be `item < q->data`.
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
        if(t->left==NULL&&t->right==NULL) // @@ This places the print in a pre-order position. To output leaf nodes from left to right, an in-order traversal is required. The condition and print statement should be moved between the two recursive calls.
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
    preorder(root, height);
    return 0;
}