#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag;
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ The variable 'flag' is not initialized, and this assignment only updates when a non-zero digit is found, but the loop continues and may overwrite the first non-zero index. Also, the loop starts at i=2, skipping index 1 which could be the decimal point.
        }
        
        if(flag == n-1){ // @@ This condition incorrectly checks if the last character is the first non-zero digit, but 'flag' may be uninitialized if all digits after decimal are zero, leading to undefined behavior.
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", n=20, but the exponent should be -8, not n-2=18.
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ The exponent calculation is wrong. For the given input, flag would be 8 (index of '9'), so flag-1=7, but the expected exponent is -8. The exponent should be -(flag - 1) where flag is the index of the first non-zero digit after the decimal, but the decimal point is at index 1, so the correct exponent is -(flag - 2).
        }
    }
    
    else{
        int flag;
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ This sets flag to the index before the decimal point, but for numbers like "123.456", the exponent should be 2 (since 123.456 = 1.23456e2), not i-1 which would be 2 for i=3, but this logic fails for numbers with no digits before decimal or multiple digits.
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ The exponent calculation is incorrect. For input "123.456", flag would be 2, but the correct exponent is 2 (since 123.456 = 1.23456e2), which coincidentally matches, but for "1.23", flag would be 0, giving e0, which is correct, but for "10.5", flag would be 1, giving e1, but the correct exponent is 1 (10.5 = 1.05e1), so it works only when the number has exactly one digit before the decimal.
    }
    return 0;
}