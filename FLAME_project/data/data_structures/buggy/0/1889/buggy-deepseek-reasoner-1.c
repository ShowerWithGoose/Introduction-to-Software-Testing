#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    gets(s);
    printf("%c", s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == 45) {
            if (s[i - 1] >= 65 && s[i - 1] <= 90 && s[i + 1] >= 65 && s[i + 1] <= 90 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } else if (s[i - 1] >= 97 && s[i - 1] <= 122 && s[i + 1] >= 97 && s[i + 1] <= 122 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } else if (s[i - 1] >= 48 && s[i - 1] <= 57 && s[i + 1] >= 48 && s[i + 1] <= 57 && s[i - 1] < s[i + 1]) {
                for (int j = s[i - 1] + 1; j < s[i + 1]; j++) {
                    printf("%c", j);
                }
            } // @@ 缺少当所有扩展条件都不满足时输出'-'的else分支，导致像"B-e"中不满足扩展条件的'-'被直接跳过。
        } else
            printf("%c", s[i]);
    }
    return 0;
}