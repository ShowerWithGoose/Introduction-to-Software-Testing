#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ This line incorrectly handles the case where the number is less than 1. It prints the last digit as the base and uses len-2 as the exponent, which is wrong. For input "0.00000009123456789012", it outputs "2e-20" instead of "9.123456789012e-8". The correct approach is to find the first non-zero digit after the decimal point and count leading zeros.
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ This line is correct for numbers like "1.23" but fails for numbers with only one digit before decimal and no decimal point (e.g., "5"). The condition should also handle the case where s[1] is '\0' (end of string) for integer inputs.
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
        printf("e%d",a-1); // @@ This line calculates the exponent as a-1, which is correct for numbers like "123.45" (a=3, exponent=2), but it does not handle trailing zeros removal or cases where the number has no decimal point (e.g., "123" should output "1.23e2" but the code fails because a is uninitialized).
    }
    return 0;
}