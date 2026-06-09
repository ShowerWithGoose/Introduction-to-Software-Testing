#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ @@ [The condition checks s[i+1]=='-' but does not verify that s[i] and s[i+2] are of the same valid type (e.g., both lowercase, both uppercase, or both digits). Also, accessing s[i+2] without ensuring i+2 is within bounds leads to undefined behavior.]
            
            if(s[i]>='A' && s[i+2]<='Z'){ @@ [Incorrect condition: should check both s[i] >= 'A' AND s[i] <= 'Z' AND s[i+2] >= 'A' AND s[i+2] <= 'Z'. Current condition only checks lower bound for s[i] and upper bound for s[i+2], allowing invalid mixes like '0'-'Z'.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Modifying loop variable i inside the for-loop header is incorrect and causes skipping of characters. Also, modifying s[i] (the original string) is wrong—it should use a temporary variable for printing.]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ @@ [Same issue as above: incomplete range check. Should ensure both ends are digits. Also, after the first if block, i has already been incremented, so this and next if may access invalid indices or wrong characters.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Same error: modifies s[i] and uses i incorrectly in loop control.]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ @@ [Same incomplete condition and logic errors as above.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Same critical errors: corrupts input string and misuses loop variable.]
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } @@ [This else only pairs with the last if, not the entire group. So if none of the prior ifs match, it prints s[i], but if any earlier if matched (even partially), this is skipped incorrectly. Also, after expansion, the '-' and next char should be skipped, but logic is flawed.]
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}