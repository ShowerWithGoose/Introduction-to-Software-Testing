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
            if(i==1) printf("."); // @@ This incorrectly inserts a decimal point at position 1 regardless of the original number's structure. For input like "87899.9999999999000999", flag is 5, so the code should move the decimal point to after the first digit, but this logic simply prints a dot at index 1, losing digits and misplacing the decimal.
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1); // @@ The exponent calculation is wrong. For "87899.9999999999000999", flag=5, so flag-1=4, but the correct exponent should be 4 (since 87899.999... = 8.78999...e4). However, the output shows "e4" which is correct in value, but the base is incorrectly formatted due to the previous error.
    }     
    else
    {
        if(c[0]!='0') puts(c); // @@ When flag==1 and first digit is non-zero (e.g., "1.23"), this prints the original string without scientific notation, but the problem requires scientific notation for all inputs. For example, "1.23" should output "1.23e0", not just "1.23".
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
                
            else printf("e-%d",count);
        }
    }
    
return 0;
}