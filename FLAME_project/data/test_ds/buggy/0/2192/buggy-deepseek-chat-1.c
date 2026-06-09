#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Error: The condition should check both characters are uppercase letters, but s[i+2]<='Z' alone does not ensure s[i+2] is uppercase; it should be s[i+2]>='A' && s[i+2]<='Z'. Also, the condition does not check that s[i] is uppercase (it only checks s[i]>='A' but not s[i]<='Z'), so it may incorrectly process non-letter characters.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Error: The condition should check both characters are digits, but s[i+2]<='9' alone does not ensure s[i+2] is a digit; it should be s[i+2]>='0' && s[i+2]<='9'. Also, s[i]>='0' does not check s[i]<='9', so it may incorrectly process non-digit characters.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Error: The condition should check both characters are lowercase letters, but s[i+2]<='z' alone does not ensure s[i+2] is lowercase; it should be s[i+2]>='a' && s[i+2]<='z'. Also, s[i]>='a' does not check s[i]<='z', so it may incorrectly process non-letter characters.
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