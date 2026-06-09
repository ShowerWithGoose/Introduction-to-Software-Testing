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
                shu[++k] = s[i] * (-1); // @@ [Error: Multiplying the operator character by -1 does not produce a unique negative value to represent the operator; it creates an arbitrary integer that may conflict with actual numbers. The correct approach is to store the operator as a separate character or use a different encoding.]
        }

    }


    for (int y = 1; y <= k ; y++) {
        if (shu[y] == '*' * (-1)) { // @@ [Error: This comparison attempts to check if the stored value equals the negative of the ASCII value of '*', which is not a reliable way to identify operators due to the previous error. The logic for operator detection is fundamentally flawed.]
            ans[g] *= shu[y + 1];
            y = y + 1;
        } else if (shu[y] == '/' * (-1)) { // @@ [Error: Same issue as above; the operator identification is incorrect.]
            ans[g] /= shu[y + 1];
            y = y + 1;
        } else {
            ans[++g] = shu[y];

        }
    }

    key = ans[1];
    for (int h = 2; h <= g; h++) {
        if (ans[h] == '+' * (-1)) // @@ [Error: Same issue with operator identification using negative ASCII values.]
            key += ans[++h];
        else if (ans[h] == '-' * (-1)) // @@ [Error: Same issue with operator identification using negative ASCII values.]
            key -= ans[++h];
    }
    printf("%d", key);

    return 0;
}