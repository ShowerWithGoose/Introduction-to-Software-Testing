#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int i = 0, n = 0, a = 0, j = 1; // @@ [global variable 'j' is used incorrectly for both root height assignment and leaf counting; it is not needed and can lead to logical errors]
struct tree
{
    int data, high;
    struct tree *left, *right;
};
struct tree *p = NULL, *root = NULL;
struct tree *insertnum(struct tree *p, int a, int h)
{
    if(p == NULL)
    {
        p = (struct tree *)malloc(sizeof(struct tree));
        p -> data = a;
        if(j == 1)
            p -> high = j;
        else
            p -> high = h;
        p -> left = p -> right = NULL;
    }
    else if(a < p -> data)
    {
        if(p -> right == NULL && p -> left == NULL) // @@ [unnecessary and erroneous increment of global 'j'; this does not reflect correct tree depth and interferes with other logic]
            j++;
        p -> left = insertnum(p -> left, a, h + 1);
    }
    else
    {
        if(p -> right == NULL && p -> left == NULL) // @@ [same as above; unnecessary increment of global 'j']
            j++;
        p -> right = insertnum(p -> right, a, h + 1);
    }
    if(j == 1)
        root = p;
    printf("%d %d\n", p -> data, p -> high); // @@ [this prints every node during insertion, but the problem requires only leaf nodes to be output; this causes extra, incorrect output]
    return p;
}

void preorder(struct tree *root)
{
    if(root != NULL)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            printf("%d %d\n", root -> data, root -> high);
        }
        preorder(root -> left);
        preorder(root -> right);
    }
}
int main()
{
    scanf("%d", &n);
    struct tree *q = NULL;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        insertnum(root, a, 1);
    }
    preorder(root);
}