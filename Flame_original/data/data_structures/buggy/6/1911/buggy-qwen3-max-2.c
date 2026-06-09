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
        printf("error "); // @@ [The output should be "error " (lowercase and followed by a space) to match expected format; original used "Error" without space]
    else
    {
        s[++Top]=item;
    }

}
void pop( int s[ ])
{
    if(isEmpty())
        printf("error "); // @@ [The output should include a space after "error" to match expected format; missing space in original]
    else
        printf("%d ", s[Top--]);
}
int main()
{
    initStack( );
    int t,x;
    while(scanf("%d",&t)) // @@ [Loop condition should check for != EOF or == 1 to avoid infinite loop on input failure; current condition may cause undefined behavior]
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