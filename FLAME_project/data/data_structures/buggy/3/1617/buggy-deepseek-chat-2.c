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
                flag = i; // @@ The variable flag is not initialized, and this assignment overwrites previous values, only keeping the last non-zero digit index. It should find the first non-zero digit after the decimal point.
        }
        
        if(flag == n-1){ // @@ This condition incorrectly checks if the last non-zero digit is the last character, but it should check if there is only one significant digit (i.e., the first non-zero digit is also the last digit).
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ The exponent calculation is wrong. For input "0.00000009123456789012", n=20, flag=9 (index of '9'), but the exponent should be -8, not n-2=18.
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", flag=9, so flag-1=8, but the exponent should be -8 (negative), and the output shows e-8, but the base is wrong because flag points to the last non-zero digit, not the first.
        }
    }
    
    else{
        int flag;
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ This loop overwrites flag each time, but since there's only one '.', it's okay. However, flag is not initialized, and if no '.' is found, flag is undefined. Also, the exponent calculation assumes the decimal point position, but for numbers like "123.456", the exponent should be 2, not i-1 (which would be 2 if '.' is at index 3).
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ The exponent is incorrectly calculated. For a number like "123.456", flag would be 2 (index of '.' minus 1), but the correct exponent is 2 (since 123.456 = 1.23456e2). However, for numbers like "1.23", flag would be 0, giving e0, which is correct. But for numbers without a decimal point, this branch is taken incorrectly (e.g., "123" would have no '.', so flag is uninitialized).
    }
    return 0;
}