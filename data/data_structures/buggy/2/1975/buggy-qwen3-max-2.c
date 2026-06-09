#include <stdio.h>
int readinnumber()
{
    int a;
    scanf("%d",&a);
    return a;
}
char readinch()
{
    char b;
    do
    {
        scanf("%c",&b);
    }while(b==' ');
    return b;
}
int check(char b1,char b2)
{
    if(b1=='*'||b1=='/')
            return 0;
    else
        if(b2=='*'||b2=='/')
            return 1;
        else
            return 0;
}
int calculate(int x,char b,int y)
{
    if(b=='*')
        return x*y;
    if(b=='/')
        return x/y;
    if(b=='+')
        return x+y;
    if(b=='-')
        return x-y;
}
int main()
{
    int f,s,t;
    char left,right;
    f=readinnum(); // @@ [Function 'readinnum' is not defined; the correct function name is 'readinnumber']
    left=readinch();
    if(left=='=')
        printf("%d",f);
    else
    {
        s=readinnum(); // @@ [Function 'readinnum' is not defined; the correct function name is 'readinnumber']
        right=readinch();
        if(right=='=')
            printf("%d",calculate(f , left,right)); // @@ [Incorrect argument order: 'calculate' expects (int, char, int), but 'right' (char) is passed as third argument instead of an int]
        else
        {
            while(right!='=')
            {
                t=readinnum(); // @@ [Function 'readinnum' is not defined; the correct function name is 'readinnumber']
                if(check(left,right)==0)
                {
                   f=calculate(f,left,s) // @@ [Missing semicolon at the end of the statement]
                    s=t;
                    left=right;
                }
                else
                {
                    s=calculate(s,right,t);
 
                }
                right=readinch();
            }
            printf("%d",calculate(f,left,s));
        }
 
    }
    return 0;
}