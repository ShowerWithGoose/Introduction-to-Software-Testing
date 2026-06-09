#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ Variable 'flag' is uninitialized; if no non-zero digit is found, it remains indeterminate, leading to undefined behavior later.
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ This overwrites 'flag' with every non-zero digit, so it ends up as the index of the last non-zero digit instead of the first. The algorithm should stop after finding the first non-zero digit.
        }
        
        if(flag == n-1){ // @@ This condition relies on the erroneous value of 'flag' (last non-zero index). It also does not handle the case where flag is uninitialized (no non-zero digit at all).
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ Exponent calculation is incorrect; it uses the total length minus 2, which does not correctly represent the number of leading zeros after the decimal point.
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ Exponent calculation is incorrect; it should be based on the position of the first non-zero digit, not the last.
        }
    }
    
    else{
        int flag;
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1;
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag);
    }
    return 0;
}