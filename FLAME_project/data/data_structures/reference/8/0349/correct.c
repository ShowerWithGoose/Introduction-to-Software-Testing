#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, m, s;
int G[ 150 ][ 150 ];
int visited[ 150 ];
int ans[ 150 ];
int top;

void DFS( int pos )
{
    if( visited[ pos ] )
        return ;
    visited[ pos ] = 1;
    printf("%d ", pos );
    int i;
    for( i = 0; i < n; i++ )
        if( i != pos && G[ pos ][ i ] )
        {
            DFS( i );
        }
}

int q[ 200 ];
int head, rear;
void BFS( int pos )
{
    q[ ++rear ] = pos;
    int p, i;
    while( rear >= head )
    {
        p = q[ head++ ];
        if( visited[ p ] )
            continue;
        visited[ p ] = 1;
        printf("%d ", p );
        for( i = 0; i < n; i++ )
            if( !visited[ i ] && G[ p ][ i ] )
                q[ ++rear ] = i;
    }
}

void DeleteVer( int pos )
{
    int i;
    for( i = 0; i < n; i++ )
    {
        G[ pos ][ i ] = 0;
        G[ i ][ pos ] = 0;
    }
}
int main()
{
    scanf("%d%d", &n, &m );
    int u, v;
    int i;

    for( i = 0; i < m; i++ )
    {
        scanf("%d%d", &u, &v );
        G[ u ][ v ] = G[ v ][ u ] = 1;
    }
    scanf("%d", &s );

    memset( visited, 0, sizeof( int ) * n );
    DFS( 0 );
    printf("\n");

    head = 0, rear = -1;
    memset( visited, 0, sizeof( int ) * n );
    BFS( 0 );
    printf("\n");

    DeleteVer( s );

    memset( visited, 0, sizeof( int ) * n );
    DFS( 0 );
    printf("\n");

    head = 0, rear = -1;
    memset( visited, 0, sizeof( int ) * n );
    BFS( 0 );
    printf("\n");
    return 0;
}
