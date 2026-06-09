#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s); // @@ gets() is removed in the C11 standard, causing a compilation error on modern compilers; should be replaced with fgets()
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ Uninitialized variable, leads to undefined behavior if the loop condition is never met
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ Missing break statement; incorrectly finds the last non-zero digit instead of the first, causing wrong output for numbers with internal zeros
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
            printf("e-%d",flag-1);
        }
    }
    
    else{
        int flag; // @@ Uninitialized variable, leads to undefined behavior if '.' is not found
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