#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ uninitialized variable; may lead to undefined behavior if no non-zero digit found
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ should break after first non-zero; this overwrites with last index, causing incorrect base and exponent
        }
        
        if(flag == n-1){ // @@ uses flag which is last non-zero, not first; logic for integer case is wrong for numbers with more than one digit after decimal
            printf("%c",s[flag]);
            printf("e-%d",n-2);
        }
        else{
            printf("%c.",s[flag]); // @@ flag may not be the first non-zero, leading to incorrect mantissa
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1);
        }
    }
    
    else{
        int flag; // @@ uninitialized; assumed to be set by loop, but if no '.' (invalid input), used uninitialized
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