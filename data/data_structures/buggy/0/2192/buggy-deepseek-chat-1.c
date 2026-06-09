#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Error: When i is at the last character, s[i+1] and s[i+2] access out-of-bounds memory, causing undefined behavior. Also, the condition s[i]<s[i+2] does not check if both characters are of the same type (e.g., lowercase, uppercase, digit) as required.]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Error: This condition only checks the start and end of the range, but does not ensure both characters are uppercase letters. For example, 'A' to 'z' would incorrectly pass because 'z' <= 'Z' is false, but 'A' to 'Z' is correct; however, the logic is flawed because it doesn't verify that s[i] is uppercase and s[i+2] is uppercase; it only checks s[i] >= 'A' and s[i+2] <= 'Z', which could allow mixed cases like 'a' to 'Z' (since 'a' >= 'A' is true, 'Z' <= 'Z' is true).]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Error: Modifying the loop variable i inside the for loop header is incorrect and leads to unpredictable behavior. Also, modifying s[i] changes the original string, which may affect subsequent iterations and output.]
                    printf("%c",s[i]);}i=i+1; // @@ [Error: Incrementing i here skips characters, potentially missing output or causing out-of-bounds access.]
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Error: Same issue as above; condition does not ensure both are digits.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Error: Same issue; condition does not ensure both are lowercase letters.]
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