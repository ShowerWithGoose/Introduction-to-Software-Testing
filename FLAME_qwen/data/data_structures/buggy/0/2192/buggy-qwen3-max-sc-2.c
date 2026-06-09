#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; however, the primary issue is logic errors in expansion handling]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] without checking bounds may cause out-of-bounds read when i is near the end of string]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect condition: should ensure both s[i] and s[i+2] are uppercase letters, but this only checks lower bound of first and upper bound of second]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside the for-loop header and body leads to undefined behavior and skips characters]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: condition does not verify that both ends are digits; also modifies 'i' incorrectly]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same issue: incorrect range check and improper modification of loop index 'i']
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } // @@ [This 'else' only pairs with the last 'if', so cases that fail digit/lowercase checks but pass uppercase may fall through incorrectly]
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}