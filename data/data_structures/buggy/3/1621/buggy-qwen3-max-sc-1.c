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
            printf("e%d", q-1); // @@ [The exponent calculation is incorrect when the number has digits after the decimal point. For example, input "123.45" should yield exponent 2, but this code uses 'q-1' where q stops at '.', so q=3, giving e2 which is correct in this case, but logic is fragile and fails for numbers like "100.0" or "102.3". However, primary compilation error stems from 'gets'.]
        }
    }
    return 0;
}