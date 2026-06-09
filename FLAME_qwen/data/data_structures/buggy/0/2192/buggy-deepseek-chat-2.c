#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Error: When i is at the last character, s[i+1] and s[i+2] access out-of-bounds memory, causing undefined behavior. Also, the condition s[i]<s[i+2] does not check if both characters are of the same type (e.g., lowercase, uppercase, digit) as required.]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Error: This condition only checks the start and end of the range, but does not ensure both characters are uppercase letters. For example, 'A' to 'Z' would pass, but 'A' to 'z' would also pass incorrectly. It should check s[i]>='A' && s[i]<='Z' && s[i+2]>='A' && s[i+2]<='Z'.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Modifying the loop variable i inside the for loop header and body causes unpredictable behavior and breaks the outer loop logic. Also, modifying s[i] changes the original string, which may affect subsequent iterations.]
                    printf("%c",s[i]);}i=i+1; // @@ [Error: Incrementing i here skips characters and disrupts the outer loop index.]
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Error: Same issue as above; does not ensure both characters are digits.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Same loop variable modification issue.]
                    printf("%c",s[i]);}i=i+1; // @@ [Error: Same index skip issue.]
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Error: Same issue; does not ensure both characters are lowercase letters.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Same loop variable modification issue.]
                    printf("%c",s[i]);}i=i+1; // @@ [Error: Same index skip issue.]
            }
            else{
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}