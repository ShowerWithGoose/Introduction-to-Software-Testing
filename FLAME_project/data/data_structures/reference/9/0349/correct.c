#include<stdio.h>
#include<stdlib.h>

struct edge{
    int x1;
    int y1;
    int x2;
    int y2;
    int in;
    int next;
};

struct edge G[ 10000 ];

int main()
{
    int n;
    scanf("%d", &n );
    int i, j;
    for( i = 0; i < n; i++ )
    {
        scanf("%d%d", &G[ i ].x1, &G[ i ].y1 );
        scanf("%d%d", &G[ i ].x2, &G[ i ].y2 );
        G[ i ].in = 0;
        G[ i ].next = -1;
    }
    for( i = 0; i < n; i++ )
    {
        for( j = i + 1; j < n; j++ )
        {
            if( G[ i ].x1 == G[ j ].x2 && G[ i ].y1 == G[ j ].y2 )
            {
                G[ j ].next = i;
                G[ i ].in++;
            }
            if( G[ j ].x1 == G[ i ].x2 && G[ j ].y1 == G[ i ].y2 )
            {
                G[ i ].next = j;
                G[ j ].in++;
            }
        }
    }
    int max = 0;
    int x0, y0;
    int len;
    for( i = 0; i < n; i++ )
    {
        if( G[ i ].in == 0 )
        {
            len = 0;
            j = i;
            while( j != -1 )
            {
                j = G[ j ].next;
                len++;
            }
            if( len > max )
            {
                max = len;
                x0 = G[ i ].x1;
                y0 = G[ i ].y1;
            }
        }
    }
    printf("%d %d %d\n", max, x0, y0 );
    return 0;
}


