#include<stdio.h>
#include<string.h>
char c[90]={0},ans[90]={'l'};
int t,tt,ttt;
int main()
{
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    if(c[0]!='-')
    {
        for(int i=0;c[i]!=0;i++) 
        {
            if(c[i]==0) t=i-1;//数一共t位 // @@ [This condition 'c[i]==0' will never be true inside the loop because the loop condition is 'c[i]!=0'. Thus, 't' is never correctly assigned.]
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
            printf("e-%d",st); // @@ ['st' may be used uninitialized if all digits after leading zeros are zero, which violates problem constraints but still risks undefined behavior.]
        }else if(tt==1&&c[0]!='0')
        {
            printf("%se0",c); // @@ [This prints the original string including the decimal point (e.g., "5.0e0"), but expected output should be "5e0" or "5.0e0" only if there are digits after. Problem states: if integer, no decimal point. Also, if input is "5", this works, but if input is "5." it fails.]
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
            if(c[i]==0) t=i-2;//数一共t位 // @@ [Same issue: 'c[i]==0' never true in loop condition 'c[i]!=0', so 't' unused but also logic flawed.]
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
            printf("e-%d",st); // @@ ['st' may be uninitialized if no non-zero digit found, leading to undefined behavior.]
        }else if(tt==1&&c[1]!='0')
        {
            printf("%se0",c); // @@ [Same as positive case: prints "-5." as "-5.e0" or similar, which is invalid scientific notation per problem spec. Should output "-5e0".]
        }
        else{
            printf("-%c.",ans[0]);
            for(int i=1;i<ttt;i++) printf("%c",ans[i]);
            printf("e%d",tt-1);
        }
    }
    
    
    return 0;
}