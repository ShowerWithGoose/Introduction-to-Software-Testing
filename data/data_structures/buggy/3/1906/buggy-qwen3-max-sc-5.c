#include <stdio.h>
#include <string.h>

int main() {
    char a[110] = {'\0'};
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers. It should be replaced with 'fgets'.]
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
        printf("e-%d", N - 2); // @@ [The exponent calculation is incorrect. It assumes all leading zeros after "0." contribute to exponent as N-2, but it should count only the zeros before the first non-zero digit. For example, input "0.00123" should yield e-3, not e-(5-2)=e-3 coincidentally works for some cases but fails generally (e.g., "0.01" -> N=4, prints e-2 which is correct, but logic is flawed because it doesn't use 'i' which tracks first non-zero). However, the primary compilation error is due to 'gets'.]
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
            for (int s = 2; s <= N - 1; s++) { // @@ [This loop starts at index 2, skipping a[1], which is wrong. If there's no decimal point and N>1 (e.g., "123"), then a[1] is '2' and should be printed. Starting at s=2 omits the second digit.]
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
            printf("e%d", M - 1);
        }
    }
    return 0;
}