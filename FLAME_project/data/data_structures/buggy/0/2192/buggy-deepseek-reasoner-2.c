#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ // @@ The condition should also verify that s[i] and s[i+2] are of the same type (both uppercase, both lowercase, or both digits). The current condition may allow expansion across types, e.g., 'A'-'a' would incorrectly enter this block.
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ This condition only checks that s[i] is at least 'A' and s[i+2] is at most 'Z', but does not ensure that both are uppercase letters (e.g., s[i]='a' would also satisfy s[i]>='A' but is not uppercase). It should be: (s[i]>='A' && s[i]<='Z' && s[i+2]>='A' && s[i+2]<='Z')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ This condition is insufficient (only checks lower bound of s[i] and upper bound of s[i+2]) and should be changed to else if to prevent falling through after the previous if block executes. Additionally, should check: (s[i]>='0' && s[i]<='9' && s[i+2]>='0' && s[i+2]<='9').
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Same issues: insufficient condition and should be else if. Should check: (s[i]>='a' && s[i]<='z' && s[i+2]>='a' && s[i+2]<='z').
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } // @@ This else belongs only to the last if. Because the previous ifs are not chained with else if, after a successful expansion (e.g., uppercase) the code still reaches this else when the lowercase condition fails, causing the dash '-' to be printed incorrectly.
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}