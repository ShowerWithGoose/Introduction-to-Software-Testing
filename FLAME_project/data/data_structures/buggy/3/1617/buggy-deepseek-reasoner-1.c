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
                flag = i; // @@ This overwrites each time, so flag becomes the last non-zero digit instead of the first. Should break after finding the first non-zero digit.
        }
        
        if(flag == n-1){
            printf("%c",s[flag]);
            printf("e-%d",n-2);
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e%d",flag-1); // @@ Missing minus sign before exponent. For numbers less than 1, exponent is negative, so it should be printf("e-%d",flag-1);
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