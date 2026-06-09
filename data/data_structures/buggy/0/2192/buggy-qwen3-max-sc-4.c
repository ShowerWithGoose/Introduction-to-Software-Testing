#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] can lead to out-of-bounds read when i is near the end of the string]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect condition: should check that both s[i] and s[i+2] are uppercase letters, not just s[i] >= 'A' and s[i+2] <= 'Z']
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside the for-loop header and body leads to undefined behavior and skips characters]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: incorrect range check; also modifies loop variable 'i' incorrectly]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same issue: incorrect range check and improper modification of loop variable 'i']
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}