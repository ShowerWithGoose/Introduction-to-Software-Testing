#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Error: Condition should check both characters are uppercase letters, but s[i+2]<='Z' alone is insufficient; it also needs s[i+2]>='A'. Additionally, the condition s[i]>='A' does not ensure s[i] is uppercase (could be other characters). The logic incorrectly allows expansion when s[i] is uppercase but s[i+2] could be any character <= 'Z', including symbols or lowercase letters.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Error: Condition should check both characters are digits, but s[i+2]<='9' alone is insufficient; it also needs s[i+2]>='0'. Also, the condition s[i]>='0' does not ensure s[i] is a digit (could be other characters). The logic incorrectly allows expansion when s[i] is a digit but s[i+2] could be any character <= '9'.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Error: Condition should check both characters are lowercase letters, but s[i+2]<='z' alone is insufficient; it also needs s[i+2]>='a'. Also, the condition s[i]>='a' does not ensure s[i] is lowercase (could be other characters). The logic incorrectly allows expansion when s[i] is lowercase but s[i+2] could be any character <= 'z'.
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