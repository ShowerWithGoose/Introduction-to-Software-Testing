#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    scanf("%s", s);
    int len = strlen(s);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing check that s[i+2] is also lowercase letter. Should add && (s[i+2] >= 'a' && s[i+2] <= 'z')
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= 'A' && s[i] <= 'Z') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing check that s[i+2] is also uppercase letter. Should add && (s[i+2] >= 'A' && s[i+2] <= 'Z')
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else if ((s[i] >= '0' && s[i] <= '9') && s[i + 1] == '-' && (s[i + 2] - s[i]) > 0) { // @@ Missing check that s[i+2] is also digit. Should add && (s[i+2] >= '0' && s[i+2] <= '9')
            for (j = 0; j <= s[i + 2] - s[i] - 1; j++) {
                if((s[i]+j)!='-')
                printf("%c", s[i] + j);
            }
        } else {
            if(s[i]!='-') // @@ Should not skip hyphens. This condition causes hyphens not part of expansion to be omitted. Remove the condition or change to print always.
            printf("%c", s[i]);
        }
    }

    return 0;
}