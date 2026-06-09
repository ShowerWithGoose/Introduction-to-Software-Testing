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
          if(fu2=='=') printf("%d",jisuan(shu1,fu1,shu2)); // @@ The code continues to execute the while loop even if fu2 is '=', because there is no else or return here. Although it prints the correct intermediate result, it then enters the loop condition check. However, the main logical error is inside the loop logic and the `panduan` function.
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
    if(c=='/') m=a/b;
    return m;
}

int panduan(char a,char b)
{
    if(a=='*'||a=='/')
    return 0; // @@ Logic Error: The function `panduan` is intended to determine if the current operator `fu2` (b) has higher precedence than the previous operator `fu1` (a), so that `shu2 op2 shu3` can be calculated first. If `a` is * or /, it has high precedence, so we should NOT delay calculation (return 0 means false, go to else block which calculates shu1 op1 shu2). This part is technically correct for standard precedence if we assume left-to-right for same precedence. However, look at the next line.
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
    return 1; // @@ Logic Error: This returns 1 (true) if the new operator `b` has higher precedence than `a`. In the main loop, if `panduan` returns true, it executes `shu2=jisuan(shu2,fu2,shu3)`, which is correct for higher precedence. However, the function lacks a default return value. If neither condition is met (e.g., a is + and b is -, or a is - and b is +), the function returns garbage/undefined value. This causes unpredictable behavior. It should return 0 in all other cases (left-associative or lower/equal precedence).
}