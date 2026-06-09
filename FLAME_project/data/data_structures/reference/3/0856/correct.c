#include <stdio.h>
int main() {
    char in[110], out[110] = "0";
    int i = 0, j, flag = 0, e;
    scanf("%s", in);
    while (1) {
        while (in[i] == '0' && flag == 0)
            if (in[++i] == '.') {
                flag = 1;
            }
        if (flag != 1 && flag != 2) flag = 2;
        i++;
        if (in[i] == '\0' || in[i] == '.' || flag == 1) break;
        e++;
    }
    if (flag == 2) {
        i = 0;
        while (in[i] == '0') i++;
        out[0] = in[i++];
        if (e != 0 || in[i] == '.') {
            out[1] = '.';
            for (i, j = 2; in[i] != '\0'; i++)
                if (in[i] != '.') out[j++] = in[i];
        }
    } else if (flag == 1) {
        e = -1;
        j = 2;
        while (in[i++] == '0') {
            e--;
        }
        out[0] = in[i - 1];
        if (in[i] != '\0') {
            out[1] = '.';
            while (in[i] != '\0') {
                out[j++] = in[i++];
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
    printf("%se%d", out, e);
    return 0;
}
