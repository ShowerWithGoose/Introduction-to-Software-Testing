#include <stdio.h>
#include <string.h>

int main() {
    char a[110] = {'\0'};
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. Additionally, the program lacks '#include <stdlib.h>' if needed for other functions, but more critically, 'gets' should be replaced with 'fgets'.]
    int N = strlen(a);
    if (a[0] == '0' && N != 1) {
        int i = 2;
        while (a[i] == '0') {
            i = i + 1;
        }
        int j = i;
        if ((N - j) != 1)
            printf("%c.", a[i]);
        else
            printf("%c", a[i]);
        i++;
        for (i; i <= N - 1; i++) {
            printf("%c", a[i]);
        }
        printf("e-%d", N - 2); // @@ [The exponent calculation is incorrect. It assumes the number of leading zeros after '0.' is always N-2, which is wrong. For example, input "0.00123" has N=6, so N-2=4, but correct exponent is -3. The exponent should be based on the position of the first non-zero digit, not total length.]
    } else {
        int temp = 0;
        for (int j = 0; j <= N - 1; j++) {
            if (a[j] == '.') {
                temp = 1;
                break;
            }
        }
        if (temp == 0 && N == 1) {
            printf("%ce0", a[0]);
        } else if (temp == 0 && N != 1) {
            printf("%c.", a[0]);
            for (int s = 2; s <= N - 1; s++) { // @@ [This loop starts at index 2, skipping a[1]. If there's no decimal point and N>1 (e.g., "123"), then digits start from a[1], but this skips a[1] and prints from a[2], causing missing digit(s).]
                printf("%c", a[s]);
            }
            printf("e%d", N - 1);
        } else {
            int M;
            printf("%c.", a[0]);
            for (int t = 1; t <= N - 1; t++) {
                if (a[t] != '.') {
                    printf("%c", a[t]);
                } else {
                    M = t;
                }
            }
            printf("e%d", M - 1); // @@ [Variable 'M' may be used uninitialized if the input has no '.' but the 'else' branch is entered only when temp==1 (i.e., '.' exists), so this might be safe logically, but the prior logic for detecting '.' is redundant and error-prone. However, the bigger issue is in the case without decimal point.]
        }
    }
    return 0;
}