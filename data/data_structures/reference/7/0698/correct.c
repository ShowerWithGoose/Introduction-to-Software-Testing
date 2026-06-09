#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bst
{
    int value;
    struct bst *left;
    struct bst *right;
} * p;
struct bst *insert(int d, struct bst *m)
{
    if (m == NULL)
    {
        m = (struct bst *)malloc(sizeof(struct bst));
        m->value = d;
        m->left = m->right = NULL;
        return m;
    }
    else if (d < m->value)
        m->left = insert(d, m->left);
    else
        m->right = insert(d, m->right);
    return m;
}
void bstprint(struct bst *m, int deep)
{
    if (m != NULL)
    {
        bstprint(m->left, deep + 1);
        if (m->left == NULL && m->right == NULL)
            printf("%d %d\n", m->value, deep);
        bstprint(m->right, deep + 1);
    }
}
int main(int argc, char const *argv[])
{
    int n, d;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &d);
        p = insert(d, p);
    }
    bstprint(p, 1);
    return 0;
}



