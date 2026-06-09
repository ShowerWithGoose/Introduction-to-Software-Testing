#include<stdio.h>
#include<string.h>
char c[90]={0},ans[90]={'l'}; // @@ [Initialization with 'l' is incorrect and unnecessary; should be {0} or omitted. Also, using gets() is unsafe and may cause buffer overflow, but the immediate compilation error likely stems from missing support for C99-style 'for(int i=...' in older C standards if compiler defaults to C89. However, the actual compilation error shown ("gcc: not found") is environmental, but assuming the intent is to find logical/code errors that would cause functional failure or compilation under standard settings, the use of 'gets' is deprecated/removed in modern C and will cause compilation error in C11+ unless explicitly allowed. Additionally, variable-length initialization and loop variable declarations require C99+. But the most concrete code-level issue causing potential compilation error in strict environments is the use of 'gets'.]
int t,tt,ttt;
int main()
{
    gets(c); // @@ [The function 'gets' is dangerous and has been removed from the C standard library since C11. Using it will cause a compilation error in compliant compilers (e.g., GCC with -std=c11). Should use fgets instead.]
    if(c[0]!='-')
    {
        for(int i=0;c[i]!=0;i++) // @@ [Declaring 'i' inside for-loop requires C99 or later. If compiler uses C89 by default, this causes a compilation error. However, many compilers allow it by default. The primary compilation error in the test is due to 'gets', but this could contribute in strict C89 mode.]
        {
            if(c[i]==0) t=i-1;//数一共t位
            if(c[i]=='.') tt=i;//小数点前有tt位
            if(c[i]!='.') ans[ttt++]=c[i];
        }
        if(c[0]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++) // @@ [Same C99 loop variable declaration issue as above.]
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++) // @@ [Same C99 issue.]
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st);
        }else if(tt==1&&c[0]!='0')
        {
            printf("%se0",c);
        }
        else{
            printf("%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]); // @@ [Same C99 issue.]
            printf("e%d",tt-1);
        }
    }else{
        for(int i=0;c[i]!=0;i++) // @@ [Same C99 issue.]
        {
            if(c[i]!='-'&&c[i]!='.') ans[ttt++]=c[i];
            if(c[i]==0) t=i-2;//数一共t位
            if(c[i]=='.') tt=i-1;//小数点前有tt位
        }
        if(c[1]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++) // @@ [Same C99 issue.]
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("-%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++) // @@ [Same C99 issue.]
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st);
        }else if(tt==1&&c[1]!='0')
        {
            printf("%se0",c);
        }
        else{
            printf("-%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]); // @@ [Same C99 issue.]
            printf("e%d",tt-1);
        }
    }
    
    
    return 0;
}