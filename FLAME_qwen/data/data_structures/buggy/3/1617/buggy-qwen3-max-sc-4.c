#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' may be used uninitialized if the loop doesn't execute or condition never met, leading to undefined behavior]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ [If input is "0.0", loop doesn't set 'flag', so 'flag' is uninitialized → undefined behavior]
            printf("%c",s[flag]);
            printf("e-%d",n-2);
        }
        else{
            printf("%c.",s[flag]); // @@ [Same: 'flag' might be uninitialized]
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
        printf("e%d",flag); // @@ ['flag' is uninitialized if input has no decimal point (though problem says it does), but still risky]
    }
    return 0;
}