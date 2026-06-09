#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) {
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1]) // @@ Incomplete range check; should also verify a[i-1] <= 'z' and a[i+1] >= 'a' to ensure both characters are strictly within the lowercase letter range.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1]) // @@ Incomplete range check; should also verify a[i-1] <= 'Z' and a[i+1] >= 'A' to ensure both characters are strictly within the uppercase letter range.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1]) // @@ Incomplete range check; should also verify a[i-1] <= '9' and a[i+1] >= '0' to ensure both characters are strictly within the digit range.
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

    printf("%s", b); // @@ Array b is not null-terminated, which will cause undefined behavior (printing garbage or crashing) when used with the %s format specifier.
}