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
        printf("%c.",str[j]); // @@ [When there are no digits after the first non-zero digit, a decimal point should not be printed. For input "0.9", this prints "9." instead of "9".]
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
        printf("%c.",str[0]); // @@ [If there are no fractional digits after moving the decimal point (e.g., whole numbers like "5.0" which isn't in spec but logic applies), this would incorrectly print a decimal point. However, per problem constraints, all digits are significant and there are digits after the decimal, but in cases where only one digit remains after normalization (like "9" from "0.9"), decimal point must be omitted. This line always prints a decimal point even when unnecessary.]
        for(k=1;k<j;k++)
        printf("%c",str[k]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e%d",j-1);
        }
        
        
        
        
    }

return 0;
}