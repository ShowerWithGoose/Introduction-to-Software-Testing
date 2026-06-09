#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ flag is uninitialized; if all digits after decimal are '0', flag remains undefined, leading to undefined behavior
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ This condition incorrectly assumes the last digit is the only non-zero digit; also fails when flag is uninitialized
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ Exponent calculation is incorrect; should count leading zeros after decimal point, not just n-2
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ Exponent calculation is incorrect; should be -(number of leading zeros + 1), not flag-1
        }
    }
    
    else{
        int flag; // @@ flag is uninitialized; if no decimal point is found, flag remains undefined
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ flag should be the position of the decimal point, not i-1; also missing braces for the if statement
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ flag is used but may be uninitialized; also exponent should be (position of decimal point - 1), not flag
    }
    return 0;
}