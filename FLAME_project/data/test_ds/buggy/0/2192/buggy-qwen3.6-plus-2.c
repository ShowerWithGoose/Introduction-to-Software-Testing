#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ Missing check to ensure both characters around '-' are of the same type
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Incorrect range validation; should verify both s[i] and s[i+2] are uppercase
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Modifies original string s and uses '<' instead of '<=', excluding the end character
                    printf("%c",s[i]);}i=i+1; // @@ i=i+1 incorrectly advances index and fails to skip the end character properly
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Incorrect range validation; should verify both s[i] and s[i+2] are digits
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Modifies original string s and uses '<' instead of '<='
                    printf("%c",s[i]);}i=i+1; // @@ Incorrect index advancement logic
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Incorrect range validation; should verify both s[i] and s[i+2] are lowercase
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Modifies original string s and uses '<' instead of '<='
                    printf("%c",s[i]);}i=i+1; // @@ Incorrect index advancement logic
            }
            else{ // @@ This else only pairs with the last if, causing redundant output when previous ifs match
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}