#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) {
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1]) @@ [The condition does not ensure both characters are lowercase letters; it only checks that the left char is >= 'a' and right char <= 'z', which allows mixed cases like 'Z'-'b'.]
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1]) @@ [Similarly, this condition fails to ensure both are uppercase; e.g., '0' >= 'A' is false but 'a' >= 'A' is true, so 'a'-'Z' could incorrectly pass part of the check.]
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1]) @@ [This condition also doesn't verify both are digits; e.g., 'a' >= '0' is true and '9' <= '9' is true, so 'a'-'9' would incorrectly be considered valid.]
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

    printf("%s", b); @@ [The output string `b` is not null-terminated, which leads to undefined behavior when printed with %s.]
}