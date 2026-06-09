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
    if(c=='/') m=a/b;
    return m;
}

int panduan(char a,char b)
{
    if(a=='*'||a=='/')
    return 0;
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
    return 1;
} // @@ [The function `panduan` does not handle all cases; it returns undefined value (garbage) when neither condition is met, leading to unpredictable behavior. Also, the logic for operator precedence is flawed: it should return 1 when the second operator has higher precedence than the first, but current logic may not cover all combinations correctly. Additionally, the `dufu` function skips only spaces but doesn't handle other whitespace like tabs or newlines, though problem says "may contain spaces", so this might be acceptable. However, the main issue causing incorrect evaluation is the incomplete `panduan` function and lack of proper left-to-right associativity handling for same-precedence operators. But since the error type reported was "Compilation Error" and the actual output was "/bin/sh: 1: gcc: not found", that indicates the environment lacks gcc — however, per instructions we must assume the code itself has logical/semantic errors causing wrong output on test cases. Given the provided test case input is empty, but expected output is also empty, yet program likely crashes or loops infinitely due to `dufu` reading past '=' or not properly terminating. However, based on code analysis, the critical flaw is in `panduan` returning undefined value in some paths.]