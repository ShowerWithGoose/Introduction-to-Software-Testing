#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [flag is uninitialized; if no non-zero digit is found after the decimal, flag remains undefined, leading to undefined behavior]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ [This condition assumes the last digit is the only non-zero, but it's comparing an uninitialized or stale flag; also logic is flawed: should check if only one significant digit exists]
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ [Exponent calculation is incorrect; should be based on position of first non-zero digit, not total length]
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ [Exponent should be -(flag - 1), but since flag is index in string starting from 0, and decimal starts at index 1, correct exponent is -(flag - 1) only if counting digits after decimal; actual correct exponent is -(flag - 1) but due to loop starting at i=2, flag is absolute index, so exponent should be -(flag - 1) → e.g., '0.0009' → flag=4 → exponent = -3, but flag-1=3 → prints e-3 which is correct, but only if flag is properly set. However, the bigger issue is that if multiple zeros exist, the loop sets flag to the last non-zero, not the first!]
        }
    }
    
    else{
        int flag; // @@ [flag is used without initialization if there's no '.' in the input; also, if there are multiple dots (though problem says valid input), but more critically, if the number has no decimal point, this loop never sets flag]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ [This sets flag to the index of the digit before the decimal, but if there are digits after, the exponent should be (number of digits before decimal - 1). However, this overwrites flag for every '.', and only the last '.' matters. Also, if no '.' exists, flag remains uninitialized]
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ [If input is integer like "123", flag is uninitialized → undefined behavior. Also, even if '.' exists, e.g., "12.34", flag = 1 (i=2 → i-1=1), and output is "1.234e1" which is correct, but the base should only have one digit before decimal and then rest after — this part is okay. However, the main flaw is handling of numbers starting with '0' and finding the FIRST non-zero digit, not the last.]
    }
    return 0;
}