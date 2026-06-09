#include <stdio.h>
#include <string.h>
#include <math.h>
char s[10000];
int shu[10000];
int ans[10000];
int i;

void delete (char s[]) {
    int i, j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
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
    puts(s); // @@ [Unnecessary output that corrupts the result; problem requires only the final integer output]
    for ( i = 0; i < strlen(s); i++) {
        if (s[i] > '9' || s[i] < '0') {
            shu[++k] = QSJS(start, i - 1);
            start = i + 1;
            if (s[i] != '=')
                shu[++k] = s[i] * (-1);
        }

    }


    for (int y = 1; y <= k ; y++) {
        if (shu[y] == '*' * (-1)) {
            ans[g] *= shu[y + 1];
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) {
            ans[g] /= shu[y + 1];
            y = y + 1;
        } else {
            ans[++g] = shu[y]; // @@ [ans[0] is never initialized; when first number is stored, g becomes 1, leaving ans[0] unused and causing misalignment]

        }
    }

    key = ans[1]; // @@ [Assumes ans[1] exists, but if expression starts with a number and no operators, g may be 0 or indexing may be off due to prior logic error]
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1))
            key += ans[++h]; // @@ [Using ++h skips the next operand; should use h+1 and then increment h by 1 in loop]
        else if (ans[h] == '-' * (-1))
            key -= ans[++h]; // @@ [Same issue: ++h causes skipping and potential out-of-bounds access]
    }
    printf("%d", key);

    return 0;
}