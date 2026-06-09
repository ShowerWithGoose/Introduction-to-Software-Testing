#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' may be used uninitialized if the loop doesn't execute or condition never met]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ ['flag' might be uninitialized here if all digits after decimal are zero, leading to undefined behavior]
            printf("%c",s[flag]);
            printf("e-%d",n-2);
        }
        else{
            printf("%c.",s[flag]); // @@ ['flag' might be uninitialized if no non-zero digit found after decimal point]
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1);
        }
    }
    
    else{
        int flag; // @@ [Variable 'flag' may be used uninitialized if '.' is not found in the string]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1;
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ ['flag' might be uninitialized if input has no decimal point, causing undefined behavior]
    }
    return 0;
}