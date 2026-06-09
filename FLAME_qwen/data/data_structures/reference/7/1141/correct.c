#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
    int num;
    int dep;
    struct tree *left, *right;
};
int k = 1;
typedef struct tree *ptr;
ptr insert(ptr p,int item)
{
    if(p==NULL)
    {
        p=(struct tree *)malloc(sizeof(struct tree));
        p->num = item;
        p->dep = k;
        p->left = p->right = NULL;
        k = 1;
    }
    else
    {
        k++;
        if (p->num <= item)
        {
            p->right = insert(p->right, item);
        }
        else
        {
            p->left = insert(p->left, item);
        }
    }
    return p;
}
void serch(ptr p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            printf("%d %d\n", p->num,p->dep);
        }
        serch(p->left);
        serch(p->right);
    }
}
int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    ptr root = NULL;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        root = insert(root, a[i]);
    }
    serch(root);
    return 0;
}
