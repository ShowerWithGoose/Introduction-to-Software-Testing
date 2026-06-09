#include<stdio.h>
#include<string.h>
char c[90]={0},ans[90]={'l'};
int t,tt,ttt;
int main()
{
    gets(c); // @@ [Using `gets()` is unsafe and deprecated; it was removed in C11. This may cause compilation errors with modern compilers that don't support it.]
    if(c[0]!='-')
    {
        for(int i=0;c[i]!=0;i++) 
        {
            if(c[i]==0) t=i-1;//数一共t位 // @@ [This condition `c[i]==0` will never be true inside the loop because the loop condition is `c[i]!=0`. Thus, `t` is never correctly assigned.]
            if(c[i]=='.') tt=i;//小数点前有tt位
            if(c[i]!='.') ans[ttt++]=c[i];
        }
        if(c[0]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st); // @@ [`st` may be used uninitialized if all digits after leading zeros are zero, which violates problem constraints but still risks undefined behavior.]
        }else if(tt==1&&c[0]!='0')
        {
            printf("%se0",c); // @@ [This prints the original string including the decimal point (e.g., "5.0e0"), violating the requirement that scientific notation base must have only one digit before decimal and no trailing zeros.]
        }
        else{
            printf("%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }else{
        for(int i=0;c[i]!=0;i++)
        {
            if(c[i]!='-'&&c[i]!='.') ans[ttt++]=c[i];
            if(c[i]==0) t=i-2;//数一共t位 // @@ [Same issue: `c[i]==0` never true in loop, so `t` unused/incorrect.]
            if(c[i]=='.') tt=i-1;//小数点前有tt位
        }
        if(c[1]=='0')
        {
            int st;
            for(int i=1;i<ttt;i++)
            {
                if(ans[i]!='0')
                {
                    st=i;
                    printf("-%c.",ans[i]);
                    for(int j=i+1;j<ttt;j++)
                    {
                        printf("%c",ans[j]);
                    }
                    break;
                }
            }
            printf("e-%d",st); // @@ [`st` may be used uninitialized. Also, exponent calculation logic is flawed for negative numbers starting with 0.]
        }else if(tt==1&&c[1]!='0')
        {
            printf("%se0",c); // @@ [Same as positive case: outputs original string like "-5.0e0", which is invalid scientific notation per problem spec.]
        }
        else{
            printf("-%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }
    
    
    return 0;
}