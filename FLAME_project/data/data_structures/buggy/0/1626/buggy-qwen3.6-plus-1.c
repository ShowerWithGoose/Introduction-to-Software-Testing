#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ The condition checks if s[i] is lowercase and s[i+2] > s[i], but it fails to verify that s[i+2] is also a lowercase letter. For input "B-e", s[i]='B' is not lowercase, so this block is skipped correctly, but the logic for mixed cases like "a-R" or "B-e" needs to ensure both ends are same type. However, the main error here is that when the condition is false, it goes to else. Let's look at the next conditions.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Similar to above, this checks if s[i] is uppercase and s[i+2] > s[i]. For input "B-e", s[i]='B' is uppercase, s[i+1]='-', and s[i+2]='e'. 'e' - 'B' > 0 is true (since 'e' > 'B' in ASCII). This condition evaluates to TRUE. It then expands from 'B' to 'e', which is incorrect because they are different types (uppercase vs lowercase). The code must check that s[i+2] is also an uppercase letter.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) {
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