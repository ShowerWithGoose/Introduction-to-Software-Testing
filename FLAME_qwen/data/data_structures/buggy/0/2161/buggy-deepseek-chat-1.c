#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) {
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1]) // @@ The condition should check that both characters are within the same range, not just the left is >= 'a' and right is <= 'z'. For example, 'a' and 'z' are valid, but 'a' and 'Z' should not be expanded. Also, the condition should ensure both are lowercase letters, not just the left is >= 'a' and right is <= 'z'. The correct condition should be: (a[i-1] >= 'a' && a[i-1] <= 'z' && a[i+1] >= 'a' && a[i+1] <= 'z' && a[i-1] < a[i+1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1]) // @@ Same issue: the condition should check both characters are uppercase letters: (a[i-1] >= 'A' && a[i-1] <= 'Z' && a[i+1] >= 'A' && a[i+1] <= 'Z' && a[i-1] < a[i+1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1]) // @@ Same issue: the condition should check both characters are digits: (a[i-1] >= '0' && a[i-1] <= '9' && a[i+1] >= '0' && a[i+1] <= '9' && a[i-1] < a[i+1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else {
                b[k] = a[i];
                k++;
            }

        } else {
            b[k] = a[i];
            k++;
        }
    }

    printf("%s", b);
}