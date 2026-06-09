#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' may be used uninitialized if the loop doesn't execute (e.g., when n <= 2). This leads to undefined behavior.]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
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
        int flag; // @@ [Variable 'flag' may be used uninitialized if no '.' is found in the input string, leading to undefined behavior.]
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