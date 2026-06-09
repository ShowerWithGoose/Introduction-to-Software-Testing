#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#define eps 1e-6 
char c[1000];

int main() {
    gets(c);
    int s=strlen(c);int flag;
    for(int i=0;i<s;i++)
    {
        if(c[i]=='.') 
        {
            flag=i;break;
        }
    }
    if(flag!=1) 
    {
        for(int i=0;i<s;i++)
        {
            if(i==1) printf(".");
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c); // @@ Error: When the number has one digit before the decimal point and it's non-zero (e.g., "1.23"), the output should be "1.23e0", but this line just prints the original string without the exponent.
        else
        {
            int count=0;
            for(int i=0;i<s;i++)
            {
                if(c[i]=='0') count++;
                else if(c[i]>='1'&&c[i]<='9')
                {
                    flag=i;break;
                }
            }
            printf("%c",c[flag]);
            if(flag!=s-1)
            {
                printf(".");
                for(int i=flag+1;i<s;i++)
                {
                    printf("%c",c[i]);
                }    
                printf("e-%d",count);
            }
                
            else printf("e-%d",count); // @@ Error: When the number is like "0.001" (flag is the position of '1'), and flag equals s-1 (i.e., the non-zero digit is the last character), the output should include a decimal point before the exponent, but this line omits it. For example, "0.001" should output "1e-3", but this prints "1e-3" correctly only if there is no trailing decimal point needed; however, the logic is inconsistent with the case where flag != s-1.
        }
    }
    
return 0;
}