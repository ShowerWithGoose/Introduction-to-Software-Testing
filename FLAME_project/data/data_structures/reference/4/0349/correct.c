#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char str[ 1000 ];
struct node{
    char word[ 50 ];
    int num;
    int deleted;
};
struct node list[ 1000 ];
int cmp( const void *a, const void *b )
{
    struct node aa = *(struct node* )a;
    struct node bb = *(struct node* )b;
    if( strcmp( aa.word, bb.word ) > 0 )
        return 1;
    return -1;
}
int main()
{
    FILE *in;
    in = fopen( "article.txt", "r" );
    char *p;
    int i, j;
    j = 0;
    while( fgets( str, 1000, in ) != NULL )
    {
        //定位到第一个单词
        i = 0;
        while ( str[ i ] )
        {
            while( !isalpha( str[ i ] ) )
            {
                i++;
                if( str[ i ] == '\0' )
                    break;
            }
            if( str[ i ] == '\0' )
                break;
            p = str + i;
            while( isalpha( str[ i ] ) )
            {
                if( isupper( str[ i ] ) )
                    str[ i ] += 'a' - 'A';
                i++;
            }
            str[ i ] = '\0';
            strcpy( list[ j ].word, p );
            list[ j ].num = 1;
            list[ j ].deleted = 0;
            j++;
            i++;
        }
    }
    qsort( list, j, sizeof( list[ 0 ] ), cmp );
    //处理重复的单词，并计数
    int k = 0;
    for( i = 0; i < j; i++ )
    {
        k = i + 1;
        while( k < j && strcmp( list[ k ].word, list[ i ].word ) == 0 )
        {
            list[ i ].num++;
            list[ k ].deleted = 1;
            k++;
        }
        i = k - 1;
    }
    for( i = 0; i < j; i++ )
    {
        if( !list[ i ].deleted )
            printf("%s %d\n", list[ i ].word, list[ i ].num );
    }
    return 0;
}


