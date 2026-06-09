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
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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


    for (int y = 1; y <= k ; y++) {
        if (shu[y] == '*' * (-1)) {
            ans[g] *= shu[y + 1]; // @@ [Undefined behavior: `ans[g]` is used uninitialized when `g` is 0 and no prior assignment occurred]
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) {
            ans[g] /= shu[y + 1]; // @@ [Same issue: `ans[g]` uninitialized; also potential division by zero if `shu[y+1]` is 0]
            y = y + 1;
        } else {
            ans[++g] = shu[y];

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1))
            key += ans[++h]; // @@ [Incorrect indexing: `++h` skips next element and may go out of bounds; also logic flaw in parsing]
        else if (ans[h] == '-' * (-1))
            key -= ans[++h]; // @@ [Same issue: `++h` modifies loop variable inside body causing skipped elements and possible out-of-bound access]
    }
    printf("%d", key);

    return 0;
}