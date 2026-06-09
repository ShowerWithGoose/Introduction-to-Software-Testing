#include <stdio.h>
int main() {
    char s[10000], c;
    scanf("%s", s);
     int i;
    for ( i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            if (s[i - 1] < s[i + 1] - 1) { // @@ Error: This condition does not correctly handle cases where the characters are of different types (e.g., 'a' and '9'), and it also fails to check that both characters are of the same type before comparing. The problem requires expansion only when both characters are of the same type (lowercase, uppercase, or digit) and the second is greater than the first. This condition may incorrectly trigger expansion for mixed types.
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
                printf("%c", s[i]);
            }
        } 
        else {
            printf("%c", s[i]);
        }
    }
    return 0;
}