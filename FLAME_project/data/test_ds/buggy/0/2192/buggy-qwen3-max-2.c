#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ @@ // Incorrect condition: does not verify that both s[i] and s[i+2] are of the same valid type (e.g., both lowercase, both uppercase, or both digits). Also accesses s[i+2] without ensuring it exists (buffer overread risk).
            
            if(s[i]>='A' && s[i+2]<='Z'){ @@ // Wrong bounds check: should ensure both s[i] >= 'A' AND s[i] <= 'Z', and same for s[i+2]. Current condition allows mixed cases like 'a' to 'Z'.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Modifying loop variable s[i] inside the loop corrupts the original string and breaks iteration logic. Also, loop condition uses modified s[i], causing incorrect behavior.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ @@ // Same issue: incomplete range check. Should be (s[i] >= '0' && s[i] <= '9' && s[i+2] >= '0' && s[i+2] <= '9').
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Same problem: modifying s[i] destroys input data and messes up loop control.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ @@ // Same issue: missing lower bound on s[i+2] and upper bound on s[i]. Should check both ends for both characters.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ // Again, modifying s[i] is destructive and leads to wrong output and index errors.
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } @@ // This else only pairs with the last 'if', not all three. So if first two ifs fail but third passes, this else is skipped incorrectly. Also, after expansion, the '-' and next char should be skipped, but logic is flawed.
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}