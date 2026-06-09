#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ flag is uninitialized; if all digits after decimal are non-zero, flag may be used without being set
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ This condition incorrectly checks if the last non-zero digit is at the last position, but the logic for exponent is wrong
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ Exponent calculation is incorrect; should count leading zeros after decimal point
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ Exponent calculation is incorrect; should be -(number of leading zeros + 1)
        }
    }
    
    else{
        int flag; // @@ flag is uninitialized; if there is no decimal point, flag may be used without being set
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ This sets flag to index before decimal point, but the loop continues and may overwrite flag incorrectly
        }
        printf("%c.",s[0]); // @@ Always prints a decimal point even if the number is an integer (e.g., "5" should output "5e0")
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ Exponent calculation is incorrect; should be (number of digits before decimal point - 1)
    }
    return 0;
}