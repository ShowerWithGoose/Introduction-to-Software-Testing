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
    puts(s); // @@ This line outputs the processed string to stdout, which violates the output format requirement of only printing the integer result. It should be removed or commented out.
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
            ans[g] *= shu[y + 1]; // @@ Logic error: ans[g] is uninitialized (likely 0) when the first operator is encountered. It should be initialized with the previous number (ans[g] = shu[y-1] or similar logic depending on structure) before multiplication. Also, the structure of storing numbers and operators in a single array `shu` and then processing into `ans` is flawed here because `ans[g]` hasn't been set to the left operand yet.
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) {
            ans[g] /= shu[y + 1]; // @@ Logic error: Same as above, ans[g] is uninitialized or incorrect. Division by zero might also occur if ans[g] is 0.
            y = y + 1;
        } else {
            ans[++g] = shu[y];

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1))
            key += ans[++h];
        else if (ans[h] == '-' * (-1))
            key -= ans[++h];
    }
    printf("%d", key);

    return 0;
}