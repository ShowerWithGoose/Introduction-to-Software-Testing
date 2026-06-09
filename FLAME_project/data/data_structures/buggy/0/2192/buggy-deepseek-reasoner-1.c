#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Error: Condition does not ensure both characters are uppercase; should check s[i+2] >= 'A' && s[i+2] <= 'Z'. Also missing braces for if-else chain]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Loop modifies s[i] and does not print the final character (should be <= or print after loop). After expansion, i=i+1 then for loop increments again, causing skip of '-' and later reprint of the following char]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Error: Same condition issue for digits; should check both ends. Also not part of if-else chain]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Same loop issues]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Error: Same condition issue for lowercase; should check both ends. Also not part of if-else chain]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Same loop issues]
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