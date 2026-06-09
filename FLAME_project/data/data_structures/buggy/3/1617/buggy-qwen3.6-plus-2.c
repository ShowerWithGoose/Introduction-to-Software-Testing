#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' is used uninitialized. If the loop doesn't find a non-zero digit or logic is flawed, it holds garbage. Also, logic for finding first significant digit is incorrect for general cases.]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ [This loop continues to update 'flag' until the LAST non-zero digit, not the FIRST. It should break after finding the first one.]
        }
        
        if(flag == n-1){ // @@ [Logic error: This condition checks if the last digit is the only significant one found (due to the loop flaw), but fails to handle the general case correctly. For input 0.00000009123456789012, flag becomes index of '2', not '9'.]
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ [Exponent calculation is incorrect. It assumes specific structure based on flawed flag.]
        }
        else{
            printf("%c.",s[flag]); // @@ [Prints the wrong digit as the base because flag points to the last non-zero digit instead of the first.]
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ [Exponent calculation is incorrect due to wrong flag value. For 0.00...09..., exponent should be -(number of zeros after decimal + 1).]
        }
    }
    
    else{
        int flag; // @@ [Variable 'flag' is used uninitialized if no '.' is found, though problem guarantees decimal point.]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ [Logic error: This overwrites flag every time, but effectively sets it to position before decimal. However, if there are multiple dots (invalid input) or logic issues, it's fragile. More importantly, for numbers >= 10, the exponent should be the number of digits before decimal minus 1. This calculates index of dot minus 1, which is correct for exponent IF the base is single digit. But wait, if input is 12.34, flag=1. Output e1. Correct. If input is 1.23, flag=0. Output e0. Correct.]
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