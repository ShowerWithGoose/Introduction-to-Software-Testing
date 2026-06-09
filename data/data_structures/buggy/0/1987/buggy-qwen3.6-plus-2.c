#include <stdio.h>
int main() {
    char s[10000], c;
    scanf("%s", s);
     int i;
    for ( i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            if (s[i - 1] < s[i + 1] - 1) { // @@ The condition incorrectly uses '-1', preventing expansion of adjacent characters like 'a-b'. It should be 's[i-1] < s[i+1]'. Also, accessing s[i-1] when i=0 causes out-of-bounds error.
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                        c = s[i - 1];
                        do {
                            c++;
                            printf("%c", c);
                        } while (c < s[i + 1]); // @@ The loop prints characters up to s[i+1], which will be printed again in the next iteration, causing duplication. The condition should be 'c < s[i+1] - 1'.
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
                        } while (c < s[i + 1]); // @@ Same duplication error: prints up to s[i+1], which is printed again next iteration. Condition should be 'c < s[i+1] - 1'.
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
                        } while (c < s[i + 1]); // @@ Same duplication error: prints up to s[i+1], which is printed again next iteration. Condition should be 'c < s[i+1] - 1'.
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