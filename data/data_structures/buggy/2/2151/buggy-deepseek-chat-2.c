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
    puts(s);
    for ( i = 0; i < strlen(s); i++) {
        if (s[i] > '9' || s[i] < '0') {
            shu[++k] = QSJS(start, i - 1);
            start = i + 1;
            if (s[i] != '=')
                shu[++k] = s[i] * (-1); // @@ [Error: Multiplying character code by -1 does not correctly encode the operator; it creates a negative integer that cannot be reliably distinguished from numbers or other operators, leading to incorrect parsing and logic failures.]
        }

    }


    for (int y = 1; y <= k ; y++) {
        if (shu[y] == '*' * (-1)) { // @@ [Error: Comparing with '*' * (-1) is unreliable and incorrect; the operator encoding method is flawed, so this condition may never be true or may match incorrectly.]
            ans[g] *= shu[y + 1];
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) { // @@ [Error: Same issue as above; '/' * (-1) comparison is invalid for detecting the division operator.]
            ans[g] /= shu[y + 1];
            y = y + 1;
        } else {
            ans[++g] = shu[y];

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1)) // @@ [Error: Same flawed operator encoding; '+' * (-1) does not correctly represent the plus operator.]
            key += ans[++h];
        else if (ans[h] == '-' * (-1)) // @@ [Error: Same flawed operator encoding; '-' * (-1) does not correctly represent the minus operator.]
            key -= ans[++h];
    }
    printf("%d", key);

    return 0;
}