#include<stdio.h>
#include<stdlib.h>

typedef struct _bst
{
    int num ;
    struct _bst* lchild ;
    struct _bst* rchild ;
    int height ;
}bst;

void tree ( bst* p )
{
    if ( p->lchild == NULL && p->rchild == NULL )
    printf( "%d %d\n" , p->num , p->height ) ;
    else
    {
        if ( p->lchild != NULL )
        tree(p->lchild);
        if ( p->rchild != NULL )
        tree(p->rchild);
    }
}



int main()
{
    bst * head =NULL , *p ;
    head = (bst*) malloc (sizeof(bst*));
    head->height = 1 ;
    head->num = 0 ;
    head->lchild = NULL ;
    head->rchild = NULL ;
    int n = 0 ;
    scanf ( "%d" , &n ) ;

    int k = 0 ;
    scanf ( "%d" , &k ) ;
    head->num = k ;
    for ( int i = 1 ; i < n ; i ++ )
    {
        int in = 0 , h = 1 ;
        scanf ( "%d" , &in ) ;//读入输入的数据
        p = head ;
        while (1)
        {
            h++ ;//记录高度
            if ( in < p->num )//放左边
            {
                if ( p->lchild != NULL )
                p = p->lchild ;
                else
                {
                    bst *temp = p ;
                    p = ( bst* ) malloc ( sizeof (bst*) ) ;
                    p->lchild = NULL ;
                    p->rchild = NULL ;
                    temp->lchild = p ;
                    p->num = in ;
                    p->height = h ;
                    break ;
                }
            }
            else
            {
                if ( p->rchild != NULL )
                p = p->rchild ;
                else
                {
                    bst *temp = p ;
                    p = ( bst* ) malloc ( sizeof (bst*) ) ;
                    p->lchild = NULL ;
                    p->rchild = NULL ;
                    temp->rchild = p ;
                    p->num = in ;
                    p->height = h ;
                    break ;
                }
            }
        }
    }
    tree( head );
    return 0 ;
}
