#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c);
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]);
        for(int m=k+1; m<=len; m++)
        {
            printf("%c", c[m]); // @@ [Loop runs to m<=len, which accesses c[len], i.e., the null terminator '\0', causing an extra null character in output]
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
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect for numbers >= 1 with a decimal point; it uses q (position of '.') but doesn't adjust correctly for scientific notation]
        }
    }
    return 0;
}