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
    f=readinnum(); // @@ [Error: Function name mismatch. The function is defined as 'readinnumber' but called as 'readinnum'. This causes an implicit declaration warning/error.]
    left=readinch();
    if(left=='=')
        printf("%d",f);
    else
    {
        s=readinnum();
        right=readinch();
        if(right=='=')
            printf("%d",calculate(f , left,right));
        else
        {
            while(right!='=')
            {
                t=readinnum();
                if(check(left,right)==0)
                {
                   f=calculate(f,left,s) // @@ [Error: Missing semicolon at the end of the statement. This causes a compilation error "expected ';' before 's'".]
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