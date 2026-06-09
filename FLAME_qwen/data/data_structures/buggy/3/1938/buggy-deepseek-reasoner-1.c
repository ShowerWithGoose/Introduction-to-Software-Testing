#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int i=0,flag=0;
    if(strchr(s,'.')==NULL) // @@ The input always contains a decimal point, so this branch is unnecessary and likely leads to incorrect handling.
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
        printf("e%d",len-1); // @@ Exponent calculation len-1 is not always correct; for numbers like "10" it may work, but the whole integer case is questionable.
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
                if(flag==2) // @@ This condition incorrectly prints the decimal point after the second significant digit instead of immediately after the first.
                {
                    printf(".");
                }
                if(flag!=0) // @@ This prints all digits after the first non-zero digit but does not include the decimal point at the correct position.
                {
                    printf("%c",s[i]);
                }
            }
            printf("e%d",2-len); // @@ Exponent formula is wrong; it should be based on the number of zeros after the decimal point before the first non-zero digit.
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