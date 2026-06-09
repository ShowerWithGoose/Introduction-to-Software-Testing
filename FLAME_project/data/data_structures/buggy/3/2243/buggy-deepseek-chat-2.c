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
        printf("%c.",str[j]); // @@ This line always prints a decimal point, but when the number has only one significant digit after the decimal point (e.g., "0.9"), the output should be an integer without a decimal point (e.g., "9e-1").
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
        printf("%c.",str[0]); // @@ This line always prints a decimal point, but when the number has only one digit before the decimal point and no other digits after the decimal point (e.g., "1.0" is not possible per spec, but for cases like "0.9" handled above), the output should not have a decimal point if the base is an integer.
        for(k=1;k<j;k++)
        printf("%c",str[k]);
        for(k=j+1;k<=strlen(str)-1;k++)
        printf("%c",str[k]);
        printf("e%d",j-1);
        }
        
        
        
        
    }

return 0;
}