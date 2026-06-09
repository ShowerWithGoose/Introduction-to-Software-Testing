#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Accessing s[i+2] when i is near the end of string may cause out-of-bounds read, but more critically, logic checks wrong positions: should check s[i] and s[i+2] only if s[i+1] is '-', but condition assumes '-' is at i+1 while loop index is i]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect range check: does not ensure both characters are uppercase letters; e.g., 'A' <= s[i] <= 'Z' AND 'A' <= s[i+2] <= 'Z', but only checks lower bound on s[i] and upper bound on s[i+2]]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable i inside for-loop header and body leads to undefined behavior and skips characters; also modifies original string which affects future comparisons]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue as above: incorrect range validation for digits; should check both ends are digits]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Same modification of loop variable i causing logic errors]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same incorrect range check for lowercase letters]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Same loop variable misuse]
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } // @@ [This else corresponds only to the last if (lowercase), not all three; so if first two ifs fail but third passes, it prints correctly, but if none pass, it prints s[i] here, yet s[i+1] is '-' and s[i+2] exists, but original '-' and next char may not be printed properly later]
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}