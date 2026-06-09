#include<stdio.h>
#include<string.h>
char str[1001];
int main()
{    gets(str);
    int i,j,k;
    if(str[0]!='0'&&str[1]=='.')
    printf("%se0",str);
    else
    {    if(str[0]=='0')
        {for(i=2;i<=strlen(str)-1;i++)
        if(str[i]!='0')
        {j=i;
        break;
        }
        printf("%c.",str[j]); // @@ The format string "%c." always prints a decimal point after the digit. If there are no subsequent significant digits (i.e., the non-zero digit is the last one), the output will incorrectly include a trailing decimal point (e.g., "9." instead of "9"). The code should check if there are more digits to print before adding the decimal point.
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e-%d",j-1);
        }
        
        else
        {for(i=2;i<=strlen(str)-1;i++)
        if(str[i]=='.')
        {
        j=i;
        break;
        }
        printf("%c.",str[0]);
        for(k=1;k<j;k++)
        printf("%c",str[k]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e%d",j-1);
        }
        
        
        
        
    }

return 0;
}