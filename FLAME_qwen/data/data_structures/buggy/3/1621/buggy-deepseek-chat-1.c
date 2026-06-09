#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ gets() is unsafe and may cause buffer overflow; also, it reads until newline but does not handle input ending with newline properly in some environments
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]); // @@ When k reaches len (no non-zero digit found), c[k] accesses out-of-bounds memory
        for(int m=k+1; m<=len; m++) // @@ Loop condition m<=len accesses c[len] which is out-of-bounds (string terminator)
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
            printf("%ce%d", c[0], q-1); // @@ When te==1, the number has no decimal point and all digits after first are zero, but exponent q-1 may be incorrect for numbers like "100" (should be e2, but q-1 gives 2 correctly, but trailing zeros are significant per problem statement)
        }else{
            printf("%c.", c[0]);
            for(int m=1; m<len; m++)
            {
                if(c[m]!='.')
                printf("%c", c[m]);
            }
            printf("e%d", q-1); // @@ For numbers with decimal point, exponent q-1 is correct only if there is exactly one digit before decimal; but if there are multiple digits before decimal, the exponent should be (position of decimal - 1), which q-1 gives correctly, but the base output includes all digits including trailing zeros, violating "no trailing zeros" rule
        }
    }
    return 0;
}