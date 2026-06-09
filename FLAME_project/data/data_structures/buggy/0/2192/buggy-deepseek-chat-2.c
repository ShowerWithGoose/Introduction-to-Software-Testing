#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Error: The condition should check both characters are uppercase, but it only checks s[i] >= 'A' and s[i+2] <= 'Z', which allows mismatched cases like 'B' and 'F' (both uppercase) but also incorrectly includes cases where s[i] is uppercase and s[i+2] is lowercase. It should be: (s[i]>='A' && s[i]<='Z') && (s[i+2]>='A' && s[i+2]<='Z')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Error: Same issue as above; should check both are digits: (s[i]>='0' && s[i]<='9') && (s[i+2]>='0' && s[i+2]<='9')
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Error: Same issue; should check both are lowercase: (s[i]>='a' && s[i]<='z') && (s[i+2]>='a' && s[i+2]<='z')
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