#include <stdio.h>
int main() {
    char s[110], out[110] = "0";
    int i = 0, j, flag = 0, cnt;
    scanf("%s", s);
    while (1) {
        while (s[i] == '0' && flag == 0)
            if (s[++i] == '.') {
                flag = 1;
            }
        if (flag != 1 && flag != 2) flag = 2;
        i++;
        if (s[i] == '\0' || s[i] == '.' || flag == 1) break;
        cnt++;
    }
    if (flag == 2) {
        i = 0;
        while (s[i] == '0') i++;
        out[0] = s[i++];
        if (cnt != 0 || s[i] == '.') {
            out[1] = '.';
            for (i, j = 2; s[i] != '\0'; i++)
                if (s[i] != '.') out[j++] = s[i];
        }
    } else if (flag == 1) {
        cnt = -1;
        j = 2;
        while (s[i++] == '0') {
            cnt--;
        }
        out[0] = s[i - 1];
        if (s[i] != '\0') {
            out[1] = '.';
            while (s[i] != '\0') {
                out[j++] = s[i++];
            }
        }
    }
    out[j] = '\0';
    while (out[--j] == '0') {
        out[j] = '\0';
        if (out[j - 1] == '.') {
            out[j - 1] = '\0';
            break;
        }
    }
    printf("%se%d", out, cnt);
    return 0;
}
