#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] when i is near the end of string can cause out-of-bounds read, leading to undefined behavior or runtime crash; also logic checks wrong position for '-']
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Condition does not ensure both characters are uppercase letters; e.g., 'A' and 'z' would pass first part but fail second, yet mixed types should not expand]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside loop causes unpredictable iteration and skips characters]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: condition doesn't verify both ends are digits; also modifies loop index incorrectly]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same problem: incomplete type check and incorrect loop control]
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