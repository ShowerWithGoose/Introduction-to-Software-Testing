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
        printf("Error"); // @@ The problem requires outputting "error " (lowercase with a trailing space) on error, but this prints "Error" (uppercase, no space). Also, it should likely terminate or handle the state correctly, but primarily the string format is wrong compared to expected output "error ".
    else
    {
        s[++Top]=item;
    }

}
void pop( int s[ ])
{
    if(isEmpty())
        printf("error"); // @@ The problem requires outputting "error " (with a trailing space) on error. This prints "error" without a space, causing formatting issues in the output sequence (e.g., "error8" instead of "error 8").
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