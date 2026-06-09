#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int i=0,flag=0;
    if(strchr(s,'.')==NULL)
    {
        for(i=len-1;i>=1;i--)
        {
            if(s[i]!='0')
            {
                flag=i;
                break;
            }
        }
        if(flag==0)
        {
            printf("%c",s[0]);
        }
        else
        {
            printf("%c.",s[0]);
            for(i=1;i<=flag;i++)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",len-1);
    }
    else
    {
        if(s[0]=='0')
        {
            for(i=0;i<len;i++)
            {
                if(s[i]!='0'&&s[i]!='.')
                {
                    flag++;
                }
                if(flag==2)
                {
                    printf(".");
                }
                if(flag!=0)
                {
                    printf("%c",s[i]);
                }
            }
            printf("e%d",2-len); // @@ The exponent calculation is incorrect. It relies on the total string length rather than the position of the first significant digit, producing wrong exponents for numbers with multiple significant digits after the decimal point (e.g., 0.00123 yields e-5 instead of e-3).
        }
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='.')
                {
                    flag=i;
                    break;
                }
            }
            printf("%c",s[0]);
            printf(".");
            for(i=1;i<len;i++)
            {
                if(s[i]!='.')
                printf("%c",s[i]);
            }
            printf("e%d",flag-1);
        }
    }
    return 0;
}