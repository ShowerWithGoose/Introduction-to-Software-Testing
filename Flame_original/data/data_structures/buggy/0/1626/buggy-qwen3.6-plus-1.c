#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) { // @@ Loop condition does not prevent out-of-bounds access when i is near len-1, as s[i+1] and s[i+2] are accessed without checking i + 2 < len.
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check (i + 2 < len) and fails to verify s[i+2] is also a lowercase letter, violating the same-type requirement.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error: loop condition should be j <= s[i+2] - s[i] to include the end character in the expansion.
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            } // @@ Missing i += 2 here to skip the '-' and the end character, which causes them to be printed again in subsequent iterations.
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check and fails to verify s[i+2] is also an uppercase letter.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error: should include the end character.
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            } // @@ Missing i += 2 to prevent duplicate output of the expansion end character.
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check and fails to verify s[i+2] is also a digit.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error: should include the end character.
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            } // @@ Missing i += 2 to prevent duplicate output.
        } else {
            if(s[i]!='-')
            printf("%c", s[i]);
        }
    }

    return 0;
}