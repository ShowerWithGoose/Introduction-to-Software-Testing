#include <stdio.h>
int main() {
    char s[10000], c;
    scanf("%s", s);
     int i;
    for ( i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            if (s[i - 1] < s[i + 1] - 1) { @@ // This condition is incorrect. It should check that s[i-1] < s[i+1], not s[i-1] < s[i+1] - 1. The "-1" causes the expansion to skip the last character, but more critically, when s[i+1] is only one greater than s[i-1] (e.g., '0' and '1'), this condition fails and '-' is printed instead of expanding. However, in the given test case "0-8", this condition passes, so the real issue is elsewhere.
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                        c = s[i - 1];
                        do {
                            c++;
                            printf("%c", c);
                        } while (c < s[i + 1]);
                    }
                    else {
                        printf("%c", s[i]);
                    }
                }
                else {
                    if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
                        if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                            c = s[i - 1] + 1;
                        do {
                            printf("%c", c);
                            c++;
                        } while (c < s[i + 1]);
                    }
                    else {
                        printf("%c", s[i]);
                    }
                    }
                    else {
                        if (s[i - 1] >= 'A' && s[i - 1] <= 'Z'){
                            if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
                                c = s[i - 1] + 1;
                        do {
                            printf("%c", c);
                            c++;
                        } while (c < s[i + 1]);
                    }
                    else {
                        printf("%c", s[i]);
                    }
                        } 
                        else {
                            printf("%c", s[i]);
                        }
                    }
                }
            }
            else {
                printf("%c", s[i]); @@ // When the condition s[i-1] < s[i+1]-1 fails (e.g., for '7' and '8', since '7' < '8'-1 → '7'<'7' is false), it prints '-', but actually for '7'-'8', we should expand to '8'. However, in the test case "0-8", this branch is not taken. The main bug is that after expanding, the code does not skip the next two characters (the '-' and the end char), so the end char gets printed again later.
            }
        } 
        else {
            printf("%c", s[i]);
        }
    }
    return 0;
}