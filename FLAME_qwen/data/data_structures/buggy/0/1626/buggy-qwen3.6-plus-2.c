#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check `i + 2 < len` causes out-of-bounds access when `i` is near the end. Also fails to verify `s[i+2]` is a lowercase letter, violating the "same type" requirement.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error: loop condition excludes the end character `s[i+2]`. Should be `j <= s[i + 2] - s[i]` and `i` should be incremented by 2 after expansion to skip processed characters.
                if((s[i]+j)!='-') // @@ Redundant and logically unnecessary check; `s[i]+j` is a character code that will not equal `'-'` in valid alphanumeric ranges.
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check `i + 2 < len` and missing type verification for `s[i+2]`.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error in loop bound.
                if((s[i]+j)!='-') // @@ Redundant check.
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing bounds check `i + 2 < len` and missing type verification for `s[i+2]`.
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) { // @@ Off-by-one error in loop bound.
                if((s[i]+j)!='-') // @@ Redundant check.
                printf("%c", s[i] + j);
            }
        } else {
            if(s[i]!='-')
            printf("%c", s[i]);
        }
    }

    return 0;
}