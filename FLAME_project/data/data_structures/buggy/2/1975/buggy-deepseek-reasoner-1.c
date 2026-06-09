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
    f=readinnum();; // @@ [Incorrect function name: should be 'readinnumber', not 'readinnum'. This causes implicit declaration error.]
    left=readinch();
    if(left=='=')
        printf("%d",f);
    else
    {
        s=readinnum();; // @@ [Incorrect function name: should be 'readinnumber'.]
        right=readinch();
        if(right=='=')
            printf("%d",calculate(f , left,right));
        else
        {
            while(right!='=')
            {
                t=readinnum();; // @@ [Incorrect function name: should be 'readinnumber'.]
                if(check(left,right)==0)
                {
                   f=calculate(f,left,s) // @@ [Missing semicolon at end of statement.]
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