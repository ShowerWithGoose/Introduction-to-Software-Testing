#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]);
        for(int m=k+1; m<=len; m++) // @@ [Loop runs to 'm<=len', which accesses c[len] — the null terminator — causing an extra unwanted character (null or garbage) to be printed. Should be 'm < len'.]
        {
            printf("%c", c[m]);
        }
        printf("e-%d", k-1);
    }
    else if(c[0]=='0' && len==3)
    {
        printf("%c", c[2]);
        printf("e-1");
    }
    else
    {
        int q=1;
        int te=1;
        for(; q<len; q++)
        {
            if(c[q]=='.')//814.3,q=3
            {
                te=0;
                break;
            }
            if(c[q]!='0')
            {
                te=0;
            }
        }
        if(te==1)
        {
            printf("%ce%d", c[0], q-1);
        }else{
            printf("%c.", c[0]);
            for(int m=1; m<len; m++)
            {
                if(c[m]!='.')
                printf("%c", c[m]);
            }
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect. 'q' is the index of '.', so exponent should be 'q - 1', but only if the number has more than one digit before the decimal. However, in cases like "5.0", this logic fails because trailing zeros are not allowed per problem statement, yet the code doesn't handle significant digits correctly. More critically, the logic assumes all digits before '.' are non-zero, which isn't validated. But the immediate error causing wrong output is that when input is e.g., "123.45", q=3, so exponent=2, which is correct, BUT if input is "100.0", it violates problem constraints (trailing zeros not allowed), yet the program may still run. However, the main bug here is not exponent logic per se, but the earlier use of 'gets' causing compilation failure. Since the error type is Compilation Error, the primary issue is 'gets'.]
        }
    }
    return 0;
}