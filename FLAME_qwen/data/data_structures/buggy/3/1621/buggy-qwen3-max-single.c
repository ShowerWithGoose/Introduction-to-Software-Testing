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
        for(int m=k+1; m<=len; m++) // @@ [Loop runs to m<=len, which accesses c[len], i.e., one past the last valid index (valid indices are 0 to len-1). This causes undefined behavior and likely prints a null character or garbage. Should be m < len.]
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
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect. 'q' is the index of the decimal point, so the exponent should be q-1 only if the number has no leading zeros. However, this logic fails for numbers like "123.45" where q=3, exponent should be 2 (since 1.2345e2), but q-1 = 2 is correct in this case. However, the earlier loop sets 'te=0' as soon as any non-zero digit is found, but the exponent logic doesn't account for cases where there are digits after the decimal point correctly in all scenarios. But more critically, the main issue causing failure is the use of 'gets' and the out-of-bounds access.]
        }
    }
    return 0;
}