#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){ @@ [The condition checks s[i+1]=='-' but does not verify that s[i] and s[i+2] are of the same valid type (e.g., both lowercase, both uppercase, or both digits). Also, accessing s[i+2] without ensuring i+2 is within bounds leads to undefined behavior.]
            
            if(s[i]>='A' && s[i+2]<='Z'){ @@ [Incorrect range check: should ensure both s[i] >= 'A' AND s[i] <= 'Z' AND s[i+2] >= 'A' AND s[i+2] <= 'Z'. Current condition only checks lower bound for s[i] and upper bound for s[i+2], allowing invalid mixes like '0'-'Z'.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Modifying loop variable s[i] inside the loop corrupts the original string and causes incorrect iteration. Also, the loop condition skips printing the last character (s[i+2]).]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ @@ [Same issue as above: incomplete range validation. Should check both ends for digits. Also, after the first if block modifies i and s[i], this condition may run incorrectly on corrupted data.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Same problem: modifying s[i] breaks the string and loop logic; also misses printing the final character.]
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ @@ [Same incomplete range check: must verify both characters are in [a-z]. Also, due to prior modifications, s[i] may no longer be valid.]
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ @@ [Again, mutating s[i] is wrong and omits the last character of the range.]
                    printf("%c",s[i]);}i=i+1;
            }
            else{
            printf("%c", s[i]);    } @@ [This else only pairs with the last if, not the whole group. So if none of the three ifs match, it prints s[i], but if one matches partially (e.g., wrong type), it may still fall through incorrectly. Also, after expanding, the '-' and next char should be skipped, but logic is flawed.]
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}