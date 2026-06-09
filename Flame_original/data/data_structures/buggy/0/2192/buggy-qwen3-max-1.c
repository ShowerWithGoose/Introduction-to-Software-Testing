#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ [Potential out-of-bounds access: when i is near the end of string, s[i+2] may read beyond array bounds]
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ [Incorrect condition: should check both ends are uppercase, but only checks s[i] >= 'A' and s[i+2] <= 'Z'; e.g., '0'-'Z' would pass]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ [Modifying loop variable 'i' inside loop causes undefined behavior and skips characters]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ [Same issue: incorrect range check; also modifies 'i' inside loop]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ [Same issue: incorrect range check; also modifies 'i' inside loop]
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