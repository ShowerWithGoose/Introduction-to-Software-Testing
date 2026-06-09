#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12]; // @@ Array size is insufficient for N=10 with required spaces; needs at least 20 characters.

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) { // @@ Hardcoded limit 10 prints uninitialized garbage for N<10 and does not match actual permutation length.
            printf("%c", pailie[j]); // @@ Fails to output spaces between integers as specified in the output format.
        }
        printf("\n");
    }
    for (int i = 1; i <= p; i++) {
        if (flag[i] == 0) {
            flag[i] = 1;
            pailie[m] = '0' + i; // @@ Incorrectly handles i=10 (produces ':' instead of "10") and omits space separators.
            quan(m + 1, n - 1); // @@ Index increment should be 2 for single digits and 3 for 10 to account for spaces, causing data overwrite.
            flag[i] = 0;
        }
    }
    return ;
}

int main() {
    scanf("%d", &p);
    quan(0, p);
    return 0;
}