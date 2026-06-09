#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern compilers/environments, 'gets' is removed entirely, leading to a compilation error.]
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' is used uninitialized if the loop doesn't execute (e.g., when n <= 2), leading to undefined behavior. Also, if all digits after '0.' are zero, 'flag' remains uninitialized.]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i;
        }
        
        if(flag == n-1){ // @@ [If the loop never runs (n <= 2) or no non-zero digit is found, 'flag' is uninitialized, causing undefined behavior here.]
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
        int flag; // @@ [Variable 'flag' is uninitialized if there's no '.' in the string, leading to undefined behavior when used. The loop assumes a '.' exists, but problem states input always has digits before and after '.', so this might be safe per spec—but still risky if input violates assumption. However, main issue is that if '.' is at position 0 (impossible per problem), or not found, 'flag' stays uninitialized.]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1;
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ [If the input has no decimal point (though problem says it does), 'flag' is uninitialized. But more importantly, the logic for exponent is flawed: e.g., "123.45" should give "1.2345e2", but this prints "1.2345e2" only if '.' is at index 3 → flag=2, which is correct. However, the real compilation error stems from 'gets'.]
    }
    return 0;
}