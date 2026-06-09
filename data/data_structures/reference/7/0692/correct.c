#include <stdio.h>
#include <stdlib.h>
typedef struct x
{
    int val, height;
    struct x *left, *right;
} node;
void dfs(node *head)
{
    if (head == NULL)
        return;
    if (head->left == NULL && head->right == NULL)
    {
        printf("%d %d\n", head->val, head->height);
        return;
    }
    dfs(head->left);
    dfs(head->right);
    return;
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    int n, num;
    scanf("%d", &n);
    scanf("%d", &head->val);
    head->left = NULL;
    head->right = NULL;
    head->height = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &num);
        node *cur = head, *last = NULL;
        int thei = 1;
        while (cur != NULL)
        {
            last = cur;
            thei++;
            if (num < cur->val)
            {
                cur = cur->left;
                if (cur == NULL)
                {
                    node *p = (node *)malloc(sizeof(node));
                    p->val = num;
                    p->left = NULL;
                    p->right = NULL;
                    p->height = thei;
                    last->left = p;
                }
            }
            else
            {
                cur = cur->right;
                if (cur == NULL)
                {
                    node *p = (node *)malloc(sizeof(node));
                    p->val = num;
                    p->left = NULL;
                    p->right = NULL;
                    p->height = thei;
                    last->right = p;
                }
            }
        }
    }
    dfs(head);
    return 0;
}
