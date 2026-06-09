#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXSIZE 100
int  s[MAXSIZE];
int  Top;
void  initStack( )
{
    Top=-1;
}
int  isEmpty( )
{
    return Top== -1;
}
int isFull(  )
{
    return Top==MAXSIZE-1;
}
void  push( int s[ ],  int item )
{
    if( isFull() )
        printf("Error"); // @@ The problem requires outputting "error" (lowercase) followed by a space, but here it prints "Error" (capital E) without a space.
    else
    {
        s[++Top]=item;
    }

}
void pop( int s[ ])
{
    if(isEmpty())
        printf("error"); // @@ The problem requires outputting "error" followed by a space, but here there is no space after "error".
    else
        printf("%d ", s[Top--]);
}
int main()
{
    initStack( );
    int t,x;
    while(scanf("%d",&t))
    {
        if(t==-1)
            break;
        else if(t==1)
        {
            scanf("%d",&x);
            push(s,x);
        }
        else if(t==0)
        {
            pop(s);
        }
    }
    return 0;
}