#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [flag is uninitialized; if no non-zero digit is found, flag remains undefined, leading to undefined behavior]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ [This condition assumes the last digit is the only non-zero, but it's comparing an uninitialized or incorrectly set flag; also logic for exponent is wrong]
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ [Exponent calculation is incorrect; should be based on position of first non-zero digit, not total length]
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ [Exponent should be -(flag - 1), but here it's printed as negative of (flag - 1) without proper sign handling; actually, for "0.000...x", exponent is -(flag - 1), but this prints e-(flag-1) which becomes e-negative, but the value flag-1 is already positive, so it should be e-%d with (flag-1) as positive number after minus sign. However, more critically, the logic fails when there are multiple digits after first non-zero]
        }
    }
    
    else{
        int flag; // @@ [flag may remain uninitialized if there's no '.' in the input, leading to undefined behavior]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ [This sets flag to index before '.', but if there are multiple dots (though problem says valid input), or no dot, flag is undefined. Also, for numbers like "123.45", exponent should be 2, but flag becomes 2 (i=3 => flag=2), which is correct, but only if dot exists]
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ [If input has no decimal point (e.g., "123"), this branch is taken (since s[0]!='0'), but flag is never set, causing undefined output]
    }
    return 0;
}