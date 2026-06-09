#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) {
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1]) // @@ Condition does not ensure that a[i+1] is also a lowercase letter; e.g., a-B would be incorrectly expanded.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1]) // @@ Condition does not ensure that a[i+1] is also an uppercase letter.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1]) // @@ Condition does not ensure that a[i+1] is also a digit.
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

    printf("%s", b); // @@ b is not null-terminated; may print garbage and cause undefined behavior.
    return 0;
}