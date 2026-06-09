#include <stdio.h>
#include <string.h>

int flag[12] = {0}, p;
char pailie[12];

void quan(int m, int n ) {
    if (n == 0) {
        for (int j = 0; j < 10; j++) { // @@ Loop bound should be p (j < p) to print only the first p characters.
            printf("%c", pailie[j]);   // @@ Missing spaces; should print numbers separated by spaces, e.g., "%c " for all but last, then "%c" for last.
        }
        printf("\n"); // @@ After printing, the function should return to avoid falling into the subsequent recursive loop (which would degrade the stack and produce extra output). A return statement is missing here.
    }
    for (int i = 1; i <= p; i++) {
        if (flag[i] == 0) {
            flag[i] = 1;
            pailie[m] = '0' + i;
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