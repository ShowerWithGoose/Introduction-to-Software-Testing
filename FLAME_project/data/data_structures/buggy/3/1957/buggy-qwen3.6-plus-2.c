#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int len=strlen(s),a;
    if(s[0]=='0'){ // @@ The logic for handling numbers less than 1 (starting with "0.") is completely incorrect. It prints the last digit and calculates a wrong exponent, instead of finding the first significant digit after the decimal point and formatting the mantissa correctly.
        printf("%ce-%d",s[len-1],len-2); // @@ This line produces incorrect output for small numbers. It should identify the first non-zero digit after '0.', print it as the start of the mantissa, followed by remaining digits, and calculate the negative exponent based on the position of that first significant digit.
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s);
    } else if(s[0]!='0'&&s[1]!='.'){
        for(int i=0;i<len;i++){
            if(s[i]=='.'){
                a=i;
            }
        }
        printf("%c.",s[0]);
        for(int i=1;i<len;i++){
            if(s[i]!='.'){
                printf("%c",s[i]);
            }
        }
        printf("e%d",a-1);
    }
    return 0;
}