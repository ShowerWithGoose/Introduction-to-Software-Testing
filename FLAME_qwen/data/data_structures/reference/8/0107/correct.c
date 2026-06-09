#include <stdio.h>
#include <stdlib.h>

int n = 0 ;//顶点数目
int v = 0 ;//边的数目
int V[105][105] = { { 0 } } ;//邻接矩阵
int vised[105] = { 0 } ;//访问过
int line[105] = { 0 } ;//广度队列
int low = -1 , top = -1 ;

void op ( void ) ;
void clearv( void ) ;//清零vised
void visit1( int depth ) ;
void visit2( int p ) ;


int main ()
{
    scanf ( "%d %d" , &n , &v ) ;
    int n1 = 0 , n2 = 0 ;
    for ( int i = 0 ; i < v ; i++ )
    {
        scanf ( "%d %d" , &n1 , &n2 ) ;
        V[n1][n2] = 1 ;
        V[n2][n1] = 1 ;
    }//构造邻接矩阵
    int del = 0 ;//要删除的数
    scanf ( "%d" , & del ) ;
    
    op() ;

    low = -1 , top = -1 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        V[del][i] = 0 ;
        V[i][del] = 0 ;
    }
    op() ;

    return 0 ;
}

void op()
{
    visit1 ( 0 ) ;
    printf ( "\n" ) ;
    clearv() ;

    visit2 ( 0 ) ;
    printf ( "\n" ) ;
    clearv() ;
}

void clearv()
{
    for ( int i = 0 ; i < 105 ; i++ ) 
    vised[i] = 0 ;
}

void visit1( int depth )//深度优先
{
    vised[depth] = 1 ;
    if ( depth != 0 )
    printf ( " " ) ;
    printf ( "%d" , depth ) ;
    int i = 0 ;
    for ( i = 0 ; i < n ; i++ )
    {
        if ( V[depth][i] == 1 && vised[i] == 0 )
        visit1 ( i ) ;
    }
}

void visit2( int p )
{
    vised[p] = 1 ;
    if ( p != 0 )
    printf ( " " ) ;
    printf ( "%d" , p ) ;
    int i = 0 ;
    for ( i = 0 ; i < n ; i++ )
    {
        if ( V[p][i] == 1 && vised[i] == 0 )
        {
            line[++top] = i ;
            vised[i] = 1 ;
        }
    }
    if ( low < top )
    {
        low ++ ;
        visit2 ( line[low] );
    }
}

