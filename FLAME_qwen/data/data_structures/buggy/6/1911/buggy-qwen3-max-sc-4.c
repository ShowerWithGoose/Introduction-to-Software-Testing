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
        printf("error "); // @@ [The output should be "error " with a space, not "Error" (capitalized and missing space). Also, problem expects lowercase "error" followed by a space.]
    else
    {
        s[++Top]=item;
    }

}
void pop( int s[ ])
{
    if(isEmpty())
        printf("error "); // @@ [The output should be "error " with a trailing space to match expected output format. Original code prints "error" without space.]
    else
        printf("%d ", s[Top--]);
}
int main()
{
    initStack( );
    int t,x;
    while(scanf("%d",&t)) // @@ [The loop condition should check for EOF or input failure properly. Using just `scanf(...) != EOF` is safer; current condition may cause infinite loop on invalid input or EOF because scanf returns EOF (negative) which is still true in boolean context.]
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