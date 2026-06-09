#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ The condition checks if s[i] is lowercase and s[i+2] is greater, but it does not verify that s[i+2] is also a lowercase letter. For input "B-e", 'B' is uppercase, so this block is skipped correctly, but the logic for mixed cases like "a-R" or "B-e" needs to ensure both ends are the same type. The main error is in the subsequent else-if blocks or the final else. Actually, looking at "B-e": s[0]='B'. It fails the first if (not lowercase). It fails the second if? No, wait.
        // Let's trace "B-e".
        // i=0: s[0]='B'.
        // Check 1: (s[0]>='a' && s[0]<='z') -> False.
        // Check 2: (s[0]>='A' && s[0]<='Z') -> True. s[1]=='-' -> True. (s[2]-s[0]) > 0 -> ('e' - 'B') > 0 -> True (since 'e' > 'B' in ASCII).
        // So it enters the second block. This is the error. It should check if s[i+2] is also an uppercase letter.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing check that s[i+2] is also an uppercase letter ('A'-'Z'). This causes "B-e" to be expanded because 'e' > 'B' in ASCII, violating the requirement that both characters must be of the same type.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing check that s[i+2] is also a digit ('0'-'9').
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else {
            if(s[i]!='-')
            printf("%c", s[i]);
        }
    }

    return 0;
}