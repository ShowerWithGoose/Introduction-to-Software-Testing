#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagBstNode
{
    int val;
    int d;                // depth
    struct tagBstNode *l; // left
    struct tagBstNode *r; // right
} bstNode;

bstNode *newBstNode(int val, int depth)
{
    bstNode *p = (bstNode *)malloc(sizeof(bstNode));
    p->val = val;
    p->d = depth;
    p->l = NULL;
    p->r = NULL;
    return p;
}

bstNode *bstInsert(bstNode *root, int val)
{
    if (root == NULL)
    {
        root = newBstNode(val, 1);
        return root;
    }
    bstNode *p = root;
    int depth = root->d;
    while (1/*p->val != val*/)
    {
        depth++;
        if (val < p->val)
        {
            if (p->l == NULL)
            {
                p->l = newBstNode(val, depth);
                break;
            }
            p = p->l;
        }
        else
        {
            if (p->r == NULL)
            {
                p->r = newBstNode(val, depth);
                break;
            }
            p = p->r;
        }
    }
    return root;
}

void bstDestory(bstNode *root)
{
    if (root == NULL)
        return;
    bstDestory(root->l);
    bstDestory(root->r);
    free(root);
}

bool bstPrintLeaf(bstNode *node)
{
    if (node == NULL)
        return true;
    if (bstPrintLeaf(node->l) & bstPrintLeaf(node->r))
        printf("%d %d\n", node->val, node->d);
    return false;
}

int main()
{
    int nodeNum;
    scanf("%d", &nodeNum);

    bstNode *bstRoot = NULL;
    while (nodeNum--)
    {
        int val;
        scanf("%d", &val);
        bstRoot = bstInsert(bstRoot, val);
    }

    bstPrintLeaf(bstRoot);

    bstDestory(bstRoot);
    
    return 0;
}
