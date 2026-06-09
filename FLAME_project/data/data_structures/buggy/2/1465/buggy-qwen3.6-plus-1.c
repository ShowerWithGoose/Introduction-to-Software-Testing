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
          if(fu2=='=') printf("%d",jisuan(shu1,fu1,shu2)); // @@ The code continues to execute the while loop even if fu2 is '=', because there is no else or return here. Although it prints the correct intermediate result, it falls through to the while loop condition check. However, the bigger logic error is inside the loop and the priority function.
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
    return 0; // @@ Logic Error: The function 'panduan' seems to intend to return 1 if the current operator (fu2) has higher precedence than the previous (fu1), allowing us to calculate fu2 first. If fu1 is * or /, it has high precedence, so we should NOT delay its calculation (return 0). This part is technically correct for "should I calculate fu2 first?". If fu1 is *, we return 0, meaning we go to else, calculating shu1 op shu2. Correct.
    if((b=='*'||b=='/')&&(a=='+'||a=='-'))
    return 1; // @@ Logic Error: If fu1 is +/- and fu2 is */*, we return 1. This means we enter the if block: shu2 = jisuan(shu2, fu2, shu3). This correctly performs the higher precedence operation first.
    // @@ Missing Return Statement: If none of the above conditions are met (e.g., a is + and b is +, or a is - and b is -), the function reaches the end without returning a value. In C, this is undefined behavior. It likely returns garbage or 0. If it returns 0 (false), it goes to the else block: shu1 = jisuan(shu1, fu1, shu2). This is correct for left-associative operators of same precedence. However, relying on UB is an error. It should explicitly return 0.
}