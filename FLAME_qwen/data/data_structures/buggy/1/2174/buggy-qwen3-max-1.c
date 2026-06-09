#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) { // @@ [The loop prints exactly 10 characters regardless of N, causing incorrect output for N < 10 (extra garbage characters) and insufficient output for N=10 (only 10 chars printed but '10' needs two chars). Also, it doesn't handle multi-digit numbers like 10 correctly since each number is stored as a single char.]
            printf("%c", pailie[j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= p; i++) {
        if (flag[i] == 0) {
            flag[i] = 1;
            pailie[m] = '0' + i; // @@ [This fails for i=10 because '0'+10 is not the character representation of "10"; it stores a single non-printable or incorrect character instead of two characters '1' and '0'.]
            quan(m + 1, n - 1);
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