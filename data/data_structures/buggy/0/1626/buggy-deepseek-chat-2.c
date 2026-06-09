#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ [Error: The condition (s[i+2] - s[i]) > 0 does not check if s[i+2] is a lowercase letter, allowing invalid expansions like 'a-9' or 'a-Z'. Also, it does not check that s[i+2] is within the same character range, which is required by the problem.]
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ [Error: Same issue as above; does not verify s[i+2] is an uppercase letter, allowing invalid expansions like 'A-b'.]
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ [Error: Same issue; does not check s[i+2] is a digit, allowing invalid expansions like '0-a'.]
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