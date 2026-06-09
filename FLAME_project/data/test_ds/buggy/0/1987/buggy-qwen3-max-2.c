#include <stdio.h>
int main() {
    char s[10000], c;
    scanf("%s", s);
     int i;
    for ( i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            if (s[i - 1] < s[i + 1] - 1) { @@ // The condition should be s[i-1] < s[i+1], not s[i-1] < s[i+1] - 1. This causes the loop to skip valid expansions like '0-8' because '0' < '8'-1 is true, but the logic for printing starts from s[i-1]+1 and goes while c < s[i+1], which already excludes the endpoint. However, the real issue is that this condition prevents expansion when the range is only two consecutive characters (e.g., a-b), but more critically, in the test case '0-8', it works, yet the output has an extra '8' due to another bug.
                if (s[i - 1] >= '0' && s[i - 1] <= '9') {
                    if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                        c = s[i - 1];
                        do {
                            c++;
                            printf("%c", c);
                        } while (c < s[i + 1]); @@ // This loop prints from s[i-1]+1 up to s[i+1]-1, but then after the loop, the next character (s[i+1]) is printed again by the main loop when i advances, causing duplication. Specifically, after processing '-', the main loop will later print s[i+1] as a normal character, leading to double printing of the end character.
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
                        } while (c < s[i + 1]); @@ // Same issue: the end character s[i+1] will be printed again when the loop reaches it normally, causing duplication.
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
                        } while (c < s[i + 1]); @@ // Same duplication issue for uppercase.
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