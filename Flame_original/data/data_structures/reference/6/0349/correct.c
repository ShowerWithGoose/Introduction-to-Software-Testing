#include<stdio.h>
#define CAP 100
int stack[ 200 ];
int top = -1;
int IsFull( )
{
    return top == CAP - 1;
}
int IsEmpty( )
{
    return top == -1;
}
void Push( int val )
{
    if( !IsFull() )
        stack[ ++top ] = val;
    else
        printf("error ");
}
void Pop()
{
    if( !IsEmpty() )
        printf("%d ", stack[ top-- ] );
    else
        printf("error ");
}
int main()
{
    int op;
    int x;
    while( ~scanf("%d", &op ) )
    {
        getchar();
        if( op == -1 )
            break;
        if( op == 1 )
        {
            scanf( "%d", &x );
            getchar();
            Push( x );
        }
        else
        {
            Pop( );
        }
    }
    return 0;
}
