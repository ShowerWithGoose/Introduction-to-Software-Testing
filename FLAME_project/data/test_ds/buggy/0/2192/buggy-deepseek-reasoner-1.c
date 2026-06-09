#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ Condition does not ensure both characters are uppercase; also should be part of else if chain to prevent multiple blocks executing.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Modifying original string and using i as loop variable is incorrect; should use a separate variable.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ Condition does not ensure both characters are digits; should be else if.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Same issue as above.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Condition does not ensure both characters are lowercase; should be else if.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Same issue as above.
                    printf("%c",s[i]);}i=i+1;
            }
            else{ // @@ This else only attaches to the previous if, but due to independent ifs, it will execute even after a true block, causing extra output (e.g., extra hyphen).
            printf("%c", s[i]);    }
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}