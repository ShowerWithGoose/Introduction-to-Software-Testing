#include <stdio.h>
#include <string.h>

int main() {
    char a[110] = {'\0'};
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
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
        for (i; i <= N - 1; i++) { // @@ [The loop condition assumes that the input always has a decimal point at index 1, but if the input format deviates (e.g., no decimal point), this leads to undefined behavior. Also, 'N' includes the null terminator only if newline was not read, but 'gets' removes the newline, so 'N' is correct length. However, logic for exponent calculation is flawed.]
            printf("%c", a[i]);
        }
        printf("e-%d", N - 2); // @@ [Exponent calculation is incorrect. For input like "0.00123", N=6, so N-2=4, but correct exponent is -3. The exponent should be based on position of first non-zero digit after leading zeros, not total length.]
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
            for (int s = 2; s <= N - 1; s++) { // @@ [This loop starts at index 2, skipping a[1], which is valid only if the number has no decimal point and at least two digits. But if input is like "123", then a[1]='2', a[2]='3'; however, this skips '2' and prints from '3' onward — incorrect. Should start at s=1.]
                printf("%c", a[s]);
            }
            printf("e%d", N - 1); // @@ [Exponent is off by one in some cases. For "123", expected is "1.23e2", but N=3, so e2 is correct. However, due to skipped digit above, output becomes "1.3e2" which is wrong. So error stems from loop start index, not exponent itself.]
        } else {
            int M;
            printf("%c.", a[0]);
            for (int t = 1; t <= N - 1; t++) {
                if (a[t] != '.') {
                    printf("%c", a[t]);
                } else {
                    M = t; // @@ [Variable 'M' is used uninitialized if there's no '.' in the string, but this branch is only entered if temp==1 (i.e., '.' exists), so technically safe. However, 'M' is set inside else, but loop continues after setting M — acceptable but fragile.]
                }
            }
            printf("e%d", M - 1); // @@ [Correct for numbers like "123.45" → M=3 (index of '.'), exponent=2, which is right. So this part may be okay, but depends on correct parsing.]
        }
    }
    return 0;
}