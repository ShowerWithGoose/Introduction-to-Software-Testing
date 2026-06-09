#include <stdio.h>
#include <string.h>
int main() {
    char in[1001], out[10001];
    int i = 0, j = 0;
    gets(in);
    while (in[i] != '\0') {
        if (i > 0 && in[i] == '-' && in[i + 1] > in[i - 1] &&
            ((in[i - 1] >= '0' && in[i + 1] <= '9') ||
             (in[i - 1] >= 'a' && in[i + 1] <= 'z') ||
             (in[i - 1] >= 'A' && in[i + 1] <= 'Z'))) {
            while (out[j - 1] + 1 <= in[i + 1]) {
                out[j] = out[j - 1] + 1;
                j++;
            }
            i = i + 2;
        } else
            out[j++] = in[i++];
    }
    puts(out);
    return 0;
}


