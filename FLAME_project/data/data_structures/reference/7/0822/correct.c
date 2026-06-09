#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} TNode, *TNodeptr;
TNodeptr root = NULL;
int Height(TNodeptr);
void order(TNodeptr);
void Visit(TNodeptr);
int main()
{
    int n, i, val;
    TNodeptr p = NULL, q = NULL;
    scanf("%d%d", &n, &val);
    p = (TNodeptr)malloc( sizeof( TNode ) );
    p->val = val;
    p->left = p->right = NULL;
    root = p;
    for( i=1; i<n; i++ ) {
        scanf("%d", &val);
        p = (TNodeptr)malloc( sizeof( TNode ) );
        p->val = val;
        p->left = p->right = NULL;
        q = root;
        while( 1 ) {
        	if( q->val > val ) {
        		if( q->left == NULL ) {
        			q->left = p;
        			break;
				}
				else q = q->left;
			}
			else if( q->val <= val ) {
				if( q->right == NULL ) {
					q->right = p;
					break;
				}
				else q = q->right;
			}
		}
    }
    order( root );
    return 0;
}
int Height(TNodeptr p)
{
    TNodeptr t = root;
    int n = 1;
    if( t != NULL ) 
        while( !(t->val == p->val && t->left == NULL && t->right == NULL )) {
            if( t->val > p->val)
                t = t->left;
            else if( t->val <= p->val )
                t = t->right;
            n ++;
        }
    return n;
}
void order(TNodeptr p)
{
    if( p != NULL ) {
        order( p->left );
        Visit( p );
        order( p->right );
    }
}
void Visit(TNodeptr p)
{
    if( p != NULL ) {
        if( p->left == NULL && p->right == NULL )
            printf("%d %d\n", p->val, Height( p ));
	}
}

