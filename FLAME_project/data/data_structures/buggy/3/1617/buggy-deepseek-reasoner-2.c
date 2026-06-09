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
                flag = i; // @@ [This sets flag to the last non-zero digit, but should find the first non-zero digit. Should break after first non-zero found.]
        }
        
        if(flag == n-1){ // @@ [Incorrect condition: uses last non-zero index. Should check if first non-zero is the only significant digit.]
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ [Wrong exponent calculation. Should be based on first non-zero position.]
        }
        else{
            printf("%c.",s[flag]); // @@ [Uses last non-zero as first digit of mantissa; should use first non-zero.]
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ [Wrong exponent; should be -(first_nonzero - 1).]
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