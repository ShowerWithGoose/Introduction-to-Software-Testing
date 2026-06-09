#include<stdio.h>
#include<string.h>
char str[1001];
int main()
{    gets(str); // @@ This line uses gets(), which is unsafe and not standard; it may cause compilation errors or warnings. Use fgets() instead.
    int i,j,k;
    if(str[0]!='0'&&str[1]=='.')
    printf("%se0",str);
    else
    {    if(str[0]=='0')
        {for(i=2;i<=strlen(str)-1;i++) // @@ The loop condition uses strlen() each iteration, which is inefficient but not an error; however, the logic fails for numbers like "0.0" where there is no non-zero digit after the decimal point, causing j to be uninitialized.
        if(str[i]!='0')
        {j=i;
        break;
        }
        printf("%c.",str[j]); // @@ If no non-zero digit is found (e.g., input "0.0"), j remains uninitialized, leading to undefined behavior.
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