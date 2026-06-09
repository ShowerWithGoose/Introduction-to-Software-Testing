#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int val;
    int deep;
} Tree;
Tree *head, *p, *q,*t;
int a;
void ins(int val)
{
    if (val < q->val)
    {
        if (q->left == NULL)
        {
            p = (Tree *)malloc(sizeof(Tree));
            p->val = val;
            p->left = NULL;
            p->right = NULL;
            p->deep = a;
            q->left = p;
        }
        else
        {
            q = q->left;
            a++;
            ins(val);
        }
    }
    else
    {
        if (q->right == NULL)
        {
            p = (Tree *)malloc(sizeof(Tree));
            p->val = val;
            p->left = NULL;
            p->right = NULL;
            p->deep = a;
            q->right = p;
        }
        else
        {
            q = q->right;
            a++;
            ins(val);
        }
    }
}

/*#define NodeNum 100
void layerorder(Tree *t)
{
    Tree *queue[NodeNum], *p;
    int front, rear;
    if (t != NULL)
    {
        queue[0] = t;
        front = 0;
        rear = 0;
        while (front <= rear)
        {
            p = queue[front++];
            if (p->left == NULL && p->right == NULL)
                printf("%d %d\n", p->val, p->deep);
            if (p->left != NULL)
                queue[++rear] = p->left;
            if (p->right != NULL)
                queue[++rear] = p->right;
        }
    }
}*/

void dfs(Tree *t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d %d\n", t->val, t->deep);
        }
        dfs(t->left);
        dfs(t->right);
    }
}

int main()
{
    int n, x[1003];
    scanf("%d", &n);
    int i;
    q = (Tree *)malloc(sizeof(Tree));
    scanf("%d", &q->val);
    q->right = NULL;
    q->left = NULL;
    q->deep = 1;
    head = (Tree *)malloc(sizeof(Tree));
    head->left = q;
    for (i = 1; i < n; i++)
    {
        a = 2;
        scanf("%d", &x[i]);
        ins(x[i]);
        q = head->left;
    }
     dfs(q);
    //layerorder(q);
    return 0;
}
