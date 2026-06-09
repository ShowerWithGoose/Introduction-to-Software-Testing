#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
struct tree
{
    int num;
    struct tree *left, *right;
};
int height;
void charu(struct tree *head, int num);
void bianli(struct tree *p);
int main()
{
    int i, j, k, n;
    struct tree *head;
    head = (struct tree *)malloc(sizeof(struct tree));
    scanf("%d", &n);
    scanf("%d", &k);
    head->num = k;
    head->left=NULL;
    head->right=NULL;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &k);
        charu(head, k);
    }
    bianli(head);
    return 0;
}
void charu(struct tree *head, int num)
{
    struct tree *p, *q;
    q = (struct tree *)malloc(sizeof(struct tree));
    q->left = NULL;
    q->right = NULL;
    q->num = num;
    p = head;
    while (1)
    {
        if (num >= p->num)
        {
            if(p->right==NULL)
            {
                p->right = q;
                break;
            }
            else
                p = p->right;
        }
        else
        {
            if(p->left==NULL)
            {
                p->left = q;
                break;
            }
            else
                p = p->left;
        }
    }
}
void bianli(struct tree *p)
{
    if (p != NULL)
    {
        height++;
        if (p->left == NULL && p->right == NULL)
            printf("%d %d\n", p->num, height);
        bianli(p->left);
        bianli(p->right);
        height--;
    }
}
