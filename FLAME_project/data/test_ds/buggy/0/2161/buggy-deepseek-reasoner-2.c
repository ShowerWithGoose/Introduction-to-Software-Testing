#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) { // @@ [Declaration of variable inside for loop not allowed in C89; use block-scope declaration at top]
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) { // @@ [Declaration of variable inside for loop not allowed in C89; also, condition does not ensure a[i-1] <= 'z' and a[i+1] >= 'a']
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) { // @@ [Declaration of variable inside for loop not allowed in C89; also, condition does not ensure a[i-1] <= 'Z' and a[i+1] >= 'A']
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1])
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) { // @@ [Declaration of variable inside for loop not allowed in C89; also, condition does not ensure a[i-1] <= '9' and a[i+1] >= '0']
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