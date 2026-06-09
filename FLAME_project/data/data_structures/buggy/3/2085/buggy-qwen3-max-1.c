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
            if(i==1) printf("."); // @@ [This incorrectly forces a decimal point after the first digit regardless of original structure, and skips the second digit. It should output the first non-zero digit, then a '.', then the rest excluding the original decimal point.]
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c);
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
                printf("e-%d",count); // @@ [The exponent calculation is wrong: 'count' includes leading zeros before the first non-zero digit, but when the number starts with '0.', the exponent should be -(number of zeros after decimal before first non-zero + 1), not total leading zeros including the '0' before the decimal. Also, 'count' counts the '0' before the decimal as well, which is incorrect.]
            }
                
            else printf("e-%d",count);
        }
    }
    
return 0;
}