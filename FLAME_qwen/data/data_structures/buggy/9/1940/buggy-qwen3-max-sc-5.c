#include <stdio.h>

void searchr(int [][4], int *[], int, int, int *);
void searchl(int [][4], int *[], int, int, int *, int *);
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
        printf("%d %d %d %d || ", a[i][0], a[i][1], a[i][2], a[i][3]);
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        searchr(a, b, n, i, p);
        searchl(a, b, n, i, q, r);
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


void searchr(int a[][4], int *b[], int n, int i, int *p) {
    b[i] = -1; // @@ [Type mismatch: b is declared as int b[n] in main, but passed as int *b[] (i.e., int **b). This causes undefined behavior when assigning -1 to b[i].]
    for (int j = 0; j < n; j++) {
        if (b[j] == -1) { // @@ [Same type mismatch issue: comparing b[j] (which is actually an int due to array decay, but treated as pointer) with -1 leads to incorrect logic and potential crash.]
            continue;
        }
        if (a[i][2] == a[j][0] && a[i][3] == a[j][1]) {
            (*p)++;
            b[j] == -1; // @@ [This is a comparison (==), not an assignment (=). Should be b[j] = -1; to mark the segment as visited.]
            searchr(a, b, n, j, p);
            return ;
        }
    }
    return ;
}

void searchl(int a[][4], int *b[], int n, int i, int *q, int *r) {
    b[i] = -1; // @@ [Same type mismatch: b is int array, but function expects int *array (pointer to pointer).]
    for (int j = 0; j < n; j++) {
        if (b[j] == -1) { // @@ [Same type mismatch issue as above.]
            continue;
        }
        if (a[i][0] == a[j][2] && a[i][1] == a[j][3]) {
            (*q)++;
            b[j] == -1; // @@ [Should be assignment b[j] = -1;, not comparison.]
            searchl(a, b, n, j, q, r);
            return ;
        } else {
            *r = i; // @@ [This assignment happens for every non-matching j, overwriting previous values. It should only set *r once when no left extension is found.]
        }
    }
    return ;
}