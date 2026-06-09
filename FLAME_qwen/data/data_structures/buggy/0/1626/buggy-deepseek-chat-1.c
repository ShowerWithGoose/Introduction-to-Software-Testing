#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Error: The condition (s[i+2] - s[i]) > 0 only checks if the second character is greater, but does not ensure s[i+2] is a lowercase letter. It should also check that s[i+2] is within the same range [a-z]. Additionally, the loop increments i by 1 after processing, but the reference program increments i by 1 to skip the '-', which is correct; however, the condition should also verify that s[i+2] is a valid character of the same type.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Error: Same issue as above; missing check that s[i+2] is an uppercase letter.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Error: Same issue; missing check that s[i+2] is a digit.
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