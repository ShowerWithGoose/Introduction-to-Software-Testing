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
    puts(s); // @@ This line prints the expression to output, which is not required and may cause wrong output format
    for ( i = 0; i < strlen(s); i++) {
        if (s[i] > '9' || s[i] < '0') {
            shu[++k] = QSJS(start, i - 1);
            start = i + 1;
            if (s[i] != '=')
                shu[++k] = s[i] * (-1); // @@ This stores operator as negative ASCII value, but the logic for handling operators later is flawed because it doesn't correctly distinguish between operators and numbers
        }

    }


    for (int y = 1; y <= k ; y++) {
        if (shu[y] == '*' * (-1)) { // @@ This comparison is incorrect; '*' * (-1) is not a valid way to represent the operator. It should compare with the character directly or use a different approach
            ans[g] *= shu[y + 1];
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) { // @@ Same issue as above, incorrect comparison for division operator
            ans[g] /= shu[y + 1];
            y = y + 1;
        } else {
            ans[++g] = shu[y]; // @@ This incorrectly stores both numbers and operator values into ans array, causing logical errors in later processing

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1)) // @@ Incorrect comparison for addition operator
            key += ans[++h];
        else if (ans[h] == '-' * (-1)) // @@ Incorrect comparison for subtraction operator
            key -= ans[++h];
    }
    printf("%d", key);

    return 0;
}