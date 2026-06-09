#include<stdio.h>
#include<string.h>
int dushu();
int dufu();
int jisuan(int a,char c,int b);
int panduan(char a,char b);
int main()
{
    int shu1,shu2,shu3;
    char fu1,fu2;
    shu1=dushu();
    fu1=dufu();
    if(fu1=='=') printf("%d",shu1);
    else
    {
        shu2=dushu();
        fu2=dufu();
          if(fu2=='=') printf("%d",jisuan(shu1,fu1,shu2));
        while(fu2!='=')
        {
            shu3=dushu();
            if(panduan(fu1,fu2)) 
            {
                shu2=jisuan(shu2,fu2,shu3);
                fu2=dufu();
            }
            else
            {
            shu1=jisuan(shu1,fu1,shu2);
            shu2=shu3;
            fu1=fu2;
            fu2=dufu();    
            }
        }
        printf("%d",jisuan(shu1,fu1,shu2));
    }
    return 0;
}


int dushu()
{
    int a;
    scanf("%d",&a);
    return a;
}

int dufu()
{
    char c;
    do 
    {
        scanf("%c",&c);
    }
    while (c==' ');
    return c;
}

int jisuan(int a,char c,int b)
{
    int m;
    if(c=='+') m=a+b;
    if(c=='-') m=a-b;
    if(c=='*') m=a*b;
    if(c=='/') m=a/b; // @@ Division by zero is not handled, but more critically, integer division should be used as per problem; this is correct for integer division, but the logic of operator precedence is flawed.
    return m;
}

int panduan(char a,char b)
{
    if(a=='*'||a=='/')
    return 0;
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
    return 1; // @@ This function does not return a value for all paths; if neither condition is true (e.g., a is '+' and b is '+'), the function returns nothing, causing undefined behavior.
}