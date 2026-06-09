#include <stdio.h>

void searchr(int [][4], int *[], int, int, int *); // @@ Type mismatch: second parameter should be 'int *' or 'int []', not 'int *[]'
void searchl(int [][4], int *[], int, int, int *, int *); // @@ Type mismatch: second parameter should be 'int *' or 'int []', not 'int *[]'
int main() {
    int n;
    int *p, *q, *r;
    int countr = 0;
    int countl = 0;
    int start = 0;
    int result = 0;
    int first = 0;
    p = &countr;
    q = &countl;
    r = &start;
    scanf("%d", &n);
    int a[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }



        getchar();
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d || ", a[i][0], a[i][1], a[i][2], a[i][3]); // @@ Extraneous debug output; should not be printed
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        searchr(a, b, n, i, p); // @@ Type mismatch: 'b' is 'int *' but function expects 'int *[]'; also 'b' should be reset for each iteration
        searchl(a, b, n, i, q, r); // @@ Type mismatch: 'b' is 'int *' but function expects 'int *[]'; also 'b' should be reset for each iteration
        if (result < countr + countl + 1) {
            result = countr + countl + 1;
            first = start;
        }

        countr = 0;
        countl = 0;
    }
    printf("%d %d %d", result, a[first][0], a[first][1]);





    return 0;
}


void searchr(int a[][4], int *b[], int n, int i, int *p) { // @@ Parameter type mismatch: 'b' should be 'int *' instead of 'int *[]'
    b[i] = -1; // @@ Invalid: treating 'int *' as 'int *[]' – 'b[i]' is an int pointer, assigning -1 causes undefined behavior
    for (int j = 0; j < n; j++) {
        if (b[j] == -1) { // @@ Invalid: comparing int pointer to integer
            continue;
        }
        if (a[i][2] == a[j][0] && a[i][3] == a[j][1]) {
            (*p)++;
            b[j] == -1; // @@ Comparison instead of assignment; should be 'b[j] = -1;'
            searchr(a, b, n, j, p);
            return ;
        }
    }
    return ;
}

void searchl(int a[][4], int *b[], int n, int i, int *q, int *r) { // @@ Parameter type mismatch: 'b' should be 'int *' instead of 'int *[]'
    b[i] = -1; // @@ Invalid: same as in searchr
    for (int j = 0; j < n; j++) {
        if (b[j] == -1) { // @@ Invalid: same as in searchr
            continue;
        }
        if (a[i][0] == a[j][2] && a[i][1] == a[j][3]) {
            (*q)++;
            b[j] == -1; // @@ Comparison instead of assignment; should be 'b[j] = -1;'
            searchl(a, b, n, j, q, r);
            return ;
        } else {
            *r = i; // @@ Incorrect logic: sets start index for every unmatched j, should only set when no left connection found after loop
        }
    }
    return ;
}