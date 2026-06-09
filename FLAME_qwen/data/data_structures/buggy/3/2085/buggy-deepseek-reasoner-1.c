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
            if(i==1) printf(".");@@ // Error: This prints a decimal point at position 1, overwriting the second digit. It should print the first digit, then a decimal point, then the rest of the digits (including the second digit). This causes the digit at index 1 to be omitted.
            else if (c[i]!='.')printf("%c",c[i]);
        }
        printf("e%d",flag-1);
    }     
    else
    {
        if(c[0]!='0') puts(c);@@ // Error: This prints the entire input string without adding "e0". For numbers like "1.23", the expected output is "1.23e0", but this only prints "1.23".
        else
        {
            int count=0;
            for(int i=0;i<s;i++)
            {
                if(c[i]=='0') count++;@@ // Error: This counts all zeros from the beginning, including the leading zero before the decimal point. For numbers like "0.101", it would count 2 zeros (the leading zero and the zero in the middle), but the correct exponent should be -1. The count should only include zeros after the decimal point up to the first non-zero digit.
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