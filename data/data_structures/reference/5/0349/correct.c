#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
    int a;
    int b;
    struct node *next;
}List;
int inp[ 1000 ][ 2 ];
int inq[ 1000 ][ 2 ];
int t[ 10000 ][ 2 ];
int cmp( const void *a, const void *b )
{
    int *aa = ( int* )a;
    int *bb = ( int* )b;
    if( aa[ 1 ] > bb[ 1 ] )
        return -1;
    return 1;
}
List* Insert( List *head, int u, int v )
{
    List *tmp = ( List* )malloc( sizeof( struct node ) );
    tmp->a = u;
    tmp->b = v;
    tmp->next = NULL;
    if( head == NULL )
    {
        head = tmp;
        return head;
    }
    
    List *p = head;
    while( p->next != NULL )
        p = p->next;
    p->next = tmp;
    return head;
}
List* times( List *p, List *q )
{
    List *i, *j;
    List *ret = NULL;
    i = p;
    j = q;
    
    int len = 0;
    while( i != NULL )
    {
        j = q;
        while( j != NULL )
        {
            t[ len ][ 0 ] = i->a * j->a;
            t[ len ][ 1 ] = i->b + j->b;
            len++;
            j = j->next;
        }
        i = i->next;
    }
    qsort( t, len, sizeof( t[ 0 ] ), cmp );
    int k;
    for( k = 0; k < len; k++ )
        ret = Insert( ret, t[ k ][ 0 ], t[ k ][ 1 ] );
    //合并相同指数项
    List *pos = ret;
    List *tmp;
    while( pos->next != NULL )
    {
        if( pos->b == pos->next->b )
        {
            pos->a += pos->next->a;
            tmp = pos->next;
            pos->next = pos->next->next;
            free( tmp );
        }
        else
            pos = pos->next;
    }
    return ret;
}
List* input( )
{
    char in[ 1000 ] = {0};
    int u, v;
    gets( in );
    int i;
    int pos = 0;
    for( i = 0; isdigit( in[ i ] ); i++ )
    {
        u = atoi( in + i );
        while( in[ i ] != ' ' )
            i++;
        i++;
        v = atoi( in + i );
        while( in[ i ] != ' ' )
            i++;
        inp[ pos ][ 0 ] = u;
        inp[ pos ][ 1 ] = v;
        pos++;
    }
    qsort( inp, pos, sizeof( inp[ 0 ] ), cmp );

    List *ret = NULL;
    for( i = 0; i < pos; i++ )
    {
        ret = Insert( ret, inp[ i ][ 0 ], inp[ i ][ 1 ] );
        //printf("%d %d ", inp[ i ][ 0 ], inp[ i ][ 1 ] );
    }
    //printf("\n");
    return ret;
}
void output( List *head )
{
    List *tmp;
    while( head != NULL )
    {
        if( head->a != 0 )
        {
            printf("%d %d ", head->a, head->b );
        }
        tmp = head;
        head = head->next;
        free( tmp );
    }
}
int main()
{
    List *p = NULL, *q = NULL;
    p = input( );
    q = input( );
    List *ans = times( p, q );
    output( ans );
    return 0;
}
