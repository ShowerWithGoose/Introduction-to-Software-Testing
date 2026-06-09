#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ @@ Missing check that both characters around '-' are of the same type (lowercase, uppercase, or digit) and within valid ranges.
            
            if(s[i]>='A' && s[i+2]<='Z'){ @@ Condition does not ensure s[i+2] is uppercase; e.g., 'A'-'0' would incorrectly expand.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ Modifies loop variable i and string s[i], causing unpredictable behavior and outer loop disruption.
                    printf("%c",s[i]);}i=i+1; @@ Manually incrementing i after a for loop that also modifies i leads to skipping characters and potential out-of-bounds access.
            }
            if(s[i]>='0' && s[i+2]<='9'){ @@ Condition only checks left is digit, right <= '9' does not guarantee right is a digit; also no right lower bound.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ Same issue as above.
                    printf("%c",s[i]);}i=i+1; @@ Same issue as above.
            }
            if(s[i]>='a' && s[i+2]<='z'){ @@ Condition incorrectly allows uppercase letters on the right (e.g., 'Z' is <= 'z'); must also check right >= 'a'.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ Same issue as above.
                    printf("%c",s[i]);}i=i+1; @@ Same issue as above.
            }
            else{
            printf("%c", s[i]);    } @@ This else is attached only to the last if; if any previous if block executed, this else still runs, causing duplicate printing.
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}