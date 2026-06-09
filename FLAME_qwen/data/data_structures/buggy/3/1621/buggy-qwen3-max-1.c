#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]);
        for(int m=k+1; m<=len; m++) // @@ [Loop condition 'm<=len' accesses c[len], which is the null terminator '\0', leading to printing an extra unwanted character. Should be 'm < len'.]
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
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect when there are non-zero digits after the decimal point. The variable 'q' stops at the decimal point, so 'q-1' gives the number of digits before the decimal minus one, but if trailing zeros exist before non-zero digits after the decimal, this logic fails. Also, the loop above sets 'te=0' on any non-zero digit, but doesn't correctly handle cases like "100.0" vs "100.1".]
        }
    }
    return 0;
}