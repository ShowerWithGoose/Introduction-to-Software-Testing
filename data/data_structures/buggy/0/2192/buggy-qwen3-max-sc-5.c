#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] when i is near strlen(s)-2 or strlen(s)-1 leads to out-of-bounds read, undefined behavior]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Condition checks only lower bound of s[i] and upper bound of s[i+2], but doesn't ensure both are uppercase letters (e.g., '0' and 'Z' would pass incorrectly)]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside the for-loop header and body causes unpredictable loop behavior and skips characters]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: doesn't verify that both ends are digits; also modifies 'i' incorrectly]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same logical flaw: incomplete type check and incorrect loop control]
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