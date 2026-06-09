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
        printf("%c.",str[0]); // @@ [If there are no additional significant digits after the decimal point in the normalized form, the decimal point should be omitted. However, this case may not trigger for inputs like "123.45", but the logic for determining when to include the decimal point is flawed. But the primary error for the given test case is in the 'if(str[0]=='0')' branch above.]
        for(k=1;k<j;k++)
        printf("%c",str[k]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e%d",j-1);
        }
        
        
        
        
    }

return 0;
}