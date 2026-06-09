#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ @@ // Condition checks s[i+1] == '-' but doesn't verify that s[i] and s[i+2] are of the same valid type (e.g., both lowercase, both uppercase, or both digits). Also, accessing s[i+2] without ensuring i+2 is within bounds leads to undefined behavior.
            
            if(s[i]>='A' && s[i+2]<='Z'){ @@ // Incorrect condition: should check both s[i] >= 'A' AND s[i] <= 'Z' AND s[i+2] >= 'A' AND s[i+2] <= 'Z'. Current condition allows cases like s[i]='0' and s[i+2]='Z' to pass.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Modifying loop variable s[i] inside the loop corrupts the original string and affects future iterations. Also, the loop condition uses modified s[i], which breaks intended logic.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ @@ // Same issue as above: incomplete range check. Should ensure both characters are digits.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Same corruption issue: modifying s[i] changes input string and breaks loop control.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ @@ // Same issue: incomplete validation of character ranges.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Same problem: mutating s[i] during expansion.
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } @@ // This else only pairs with the last if, not all three. So if first two ifs fail but third passes, it's okay—but if all fail, it prints s[i], but then the next character (the '-') and s[i+2] may still be printed later, causing duplication or omission.
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}