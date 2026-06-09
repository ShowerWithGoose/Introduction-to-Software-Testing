#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, some compilers may not support it, leading to compilation errors.]
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]);
        for(int m=k+1; m<=len; m++) // @@ [Loop goes up to 'm<=len', which accesses c[len] — the null terminator — causing an extra character (garbage or '\0') to be printed. Should be 'm < len'.]
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
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect when there are non-zero digits after the decimal point. 'q' stops at '.', so exponent should be 'q - 1', but this fails for numbers like "123.45" where trailing digits exist — logic doesn't account for full integer part length correctly. However, primary compilation issue stems from 'gets'.]
        }
    }
    return 0;
}