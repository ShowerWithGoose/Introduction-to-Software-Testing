#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) { // @@ Fixed loop bound 10 is incorrect; it should iterate based on the actual permutation length and account for spaces between numbers.
            printf("%c", pailie[j]); // @@ Missing space separator between integers in the output as required by the format.
        }
        printf("\n");
    }
    for (int i = 1; i <= p; i++) {
        if (flag[i] == 0) {
            flag[i] = 1;
            pailie[m] = '0' + i; // @@ Incorrectly converts integer to char; fails for i=10 (requires two characters) and does not handle spacing between numbers.
            quan(m + 1, n - 1); // @@ Index increment m+1 is incorrect because it doesn't account for multi-digit numbers (like 10) or the required spaces.
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