#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] when i is near the end of string may cause out-of-bounds read, leading to undefined behavior or runtime crash; also logic checks wrong position: should check s[i]=='-' not s[i+1]]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect range check: does not ensure both characters are uppercase letters; e.g., 'A' to 'z' would pass first condition but fail type consistency]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable i inside nested loop disrupts outer loop control flow; also modifies input string during iteration which causes unpredictable behavior]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issues as above: incorrect range validation and unsafe modification of loop index]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same issues: incomplete type check (doesn't verify s[i+2] >= 'a'), and unsafe loop index manipulation]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } // @@ [This else only pairs with last if, so if none of the three type conditions match, it prints s[i], but skips handling of '-' and next char correctly]
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}