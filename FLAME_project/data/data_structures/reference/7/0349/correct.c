#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val;
    int depth;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *T = NULL;
struct TreeNode *Insert( struct TreeNode *t, int val )
{
    struct TreeNode *tmp = ( struct TreeNode* )malloc( sizeof( struct TreeNode ) );
    tmp->val = val;
    tmp->depth = 1;
    tmp->right = tmp->left = NULL;
    if( t == NULL )
    {
        t = tmp;
        return t;
    }
    struct TreeNode *p, *q;
    p = q = t;
    while( q != NULL )
    {
        p = q;
        if( val >= p->val )
            q = p->right;
        else if( val < p->val )
            q = p->left;
    }
    tmp->depth = p->depth + 1;
    if( val < p->val )
        p->left = tmp;
    else
        p->right = tmp;
    return t;
}
void MidPrint( struct TreeNode *t )
{
    if( t == NULL )
        return ;
    MidPrint( t->left );
    if( t->left == NULL && t->right == NULL )
        printf("%d %d\n", t->val, t->depth );
    MidPrint( t->right );
    return ;
}
int main()
{
    int n;
    scanf("%d", &n );
    int i;
    int x;
    for( i = 0; i < n; i++ )
    {
        scanf(" %d", &x );
        T = Insert( T, x );
    }
    MidPrint( T );
    return 0;
}
