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
        printf("error "); // @@ [The output should be "error " (lowercase and followed by a space) to match expected output format, but original prints "Error" without space]
    else
    {
        s[++Top]=item;
    }

}
void pop( int s[ ])
{
    if(isEmpty())
        printf("error "); // @@ [The output should be "error " (followed by a space), but original prints "error" without trailing space]
    else
        printf("%d ", s[Top--]);
}
int main()
{
    initStack( );
    int t,x;
    while(scanf("%d",&t)) // @@ [The loop condition should check for EOF; current condition causes infinite loop or undefined behavior when input ends because scanf returns EOF (not 0 or 1 in all cases). It should be: while(scanf("%d",&t) == 1)]
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