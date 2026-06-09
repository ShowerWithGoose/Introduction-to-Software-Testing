#include <stdio.h>
#include <string.h>
#include <math.h>
char s[10000];
int shu[10000];
int ans[10000];
int i;

void delete (char s[]) {
    int i, j = 0;
    for (int i = 0; s[i] != '\0'; i++) { // @@ Compilation error: C99-style variable declaration inside for loop; not allowed in C89.
        if (s[i] != ' ' ) {
            s[j++] = s[i];
        }

    }
    s[j] = '\0';

}

int QSJS(int start, int end) {
    int fan = 0;
    for (int x = start; x <= end; x++) {
        fan = fan * 10 + s[x] - '0';
    }
    return fan;
}

int main() {
    int start = 0;
    int k = 0;
    int g = 0;
    int key = 0;
    gets(s);
    delete (s);
    puts(s);
    for ( i = 0; i < strlen(s); i++) {
        if (s[i] > '9' || s[i] < '0') {
            shu[++k] = QSJS(start, i - 1);
            start = i + 1;
            if (s[i] != '=')
                shu[++k] = s[i] * (-1);
        }

    }


    for (int y = 1; y <= k ; y++) { // @@ Compilation error: C99-style variable declaration inside for loop; not allowed in C89.
        if (shu[y] == '*' * (-1)) {
            ans[g] *= shu[y + 1];
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) {
            ans[g] /= shu[y + 1];
            y = y + 1;
        } else {
            ans[++g] = shu[y];

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) { // @@ Compilation error: C99-style variable declaration inside for loop; not allowed in C89.
        if (ans[h] == '+' * (-1))
            key += ans[++h];
        else if (ans[h] == '-' * (-1))
            key -= ans[++h];
    }
    printf("%d", key);

    return 0;
}