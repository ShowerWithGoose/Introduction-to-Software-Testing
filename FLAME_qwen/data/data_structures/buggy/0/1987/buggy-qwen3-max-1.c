#include <stdio.h>
int main() {
    char s[10000], c;
    scanf("%s", s);
     int i;
    for ( i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            if (s[i - 1] < s[i + 1] - 1) { @@ [This condition is incorrect: it accesses s[i-1] and s[i+1] without checking if i>0 and i is not at the last character, leading to potential out-of-bounds access. Also, the logic should first verify that both surrounding characters are of the same valid type before comparing their values.]
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