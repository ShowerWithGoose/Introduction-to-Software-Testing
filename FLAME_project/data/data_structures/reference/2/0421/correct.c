#include<stdio.h>
int cal(int a,int b,char c);
int ra();
char rb();
int main()
{
    int a[3];
    char b[2];
    a[0]=ra();
    b[0]=rb();
    if (b[0] != '=')
        a[1] = ra();
    while(b[0]!='=')
    {
        if(b[0]=='*'||b[0]=='/')
        {
            a[0]=cal(a[0],a[1],b[0]);
            b[0]=rb();
            if(b[0]!='=')
                a[1]=ra();
        }
        else
        {
            b[1]=rb();
            if(b[1]=='='||b[1]=='+'||b[1]=='-')
            {
                a[0]=cal(a[0],a[1],b[0]);
                b[0]=b[1];
                if(b[0]!='=')
                    a[1]=ra();
            }
            else if(b[1]!='=')
            {
                a[2]=ra();
                a[1]=cal(a[1],a[2],b[1]);
            }
            else b[0]=b[1];
        }
    }
    printf("%d",a[0]);
    return 0;
}

int cal(int a, int b, char c)
{
    int n;
    if (c=='+')
        n=a+b;
    else if (c=='-')
        n=a-b;
    else if (c=='*')
        n=a*b;
    else
        n=a/b;
    return n;
}

int ra()
{
    int a;
    scanf(" %d", &a);
    return a;
}
char rb()
{
    char b;
    scanf(" %c", &b);
    return b;
}

