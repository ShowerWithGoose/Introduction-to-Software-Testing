#include <stdio.h>
#include <string.h>
char s[110];
int main()
{
    gets(s);
    int len=strlen(s),a;
    if(s[0]=='0'){
        printf("%ce-%d",s[len-1],len-2); // @@ Error: This branch incorrectly handles numbers like "0.xxx". It assumes the last character is the only significant digit and uses len-2 as exponent, which is wrong for numbers like "0.00123" where there are leading zeros after the decimal point. The exponent should account for the number of leading zeros.
    } else if(s[0]!='0'&&s[1]=='.'){
        printf("%se0",s); // @@ Error: This branch outputs the entire input string as the base, but for numbers like "1.23", the base should be "1.23" (which is correct), but the exponent should be 0 only if the number is already in scientific notation form (e.g., "1.23" is correct, but "12.3" would not enter this branch). However, this branch incorrectly handles cases where the input has only one digit before the decimal point (e.g., "0.5" is handled by the first branch, but "1.0" would be incorrect because trailing zeros are not allowed per problem description). The problem states no trailing zeros, so this branch is only valid for numbers like "1.23", but it fails for numbers like "1.0" (which shouldn't appear) or "1" (which has no decimal point).
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
        printf("e%d",a-1); // @@ Error: This branch assumes the decimal point is always after the first digit, but for numbers like "123.45", the exponent should be 2 (since 123.45 = 1.2345e2), but a-1 = 2 is correct. However, the base output includes all digits after the first, including trailing zeros if any (though problem says no trailing zeros). The main issue is that this branch does not handle numbers with no decimal point (e.g., "123"), where the loop to find '.' would not set 'a', leading to undefined behavior.
    }
    return 0;
}