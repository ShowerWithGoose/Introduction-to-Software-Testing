#include<stdio.h>
int num[5],numm[130][5],o,nummflag[130]; // @@ [Array sizes too small for N up to 10; num should have at least 10 elements, numm should have at least 10 columns and 3628800 rows]
int nj(int n) {
    if (n == 1)return 1;
    else return n * nj(n - 1);
}
void swap(int a, int b) {
    int tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}
void permutation(int now,int n) {
    if (now == n) {
        for (int i = 0; i < n; i++) {
            numm[o][i] = num[i]; // @@ [Accessing numm column index i which may exceed 5 for n>5; buffer overflow]
            nummflag[o] =nummflag[o]*10+num[i]; // @@ [Concatenating multi-digit numbers for N>=10 produces ambiguous flag and overflow beyond int range]
        }o++;
    }
    else {
        for (int i = now; i < n; i++) {
            swap(i, now);
            permutation(now + 1, n);
            swap(i, now);
        }
    }
}
int find(int nj) {
    int min = 999999; // @@ [Initial min too small; for N>=7 flags can exceed 999999; should use a larger sentinel like INT_MAX]
    int i = 0,ko;
    for ( ; i < nj; i++) {
        if (nummflag[i] < min && nummflag[i]>0) { min = nummflag[i]; ko = i; }
    }nummflag[ko] = 0; // @@ [If no flag >0 (e.g., after all taken), ko is uninitialized; undefined behavior]
    return ko;
}
int main() {
    int n;
    scanf_s("%d", &n); // @@ [Non-standard scanf_s; should be scanf for portability; may cause compilation error on non-MS compilers]
    num[0] = 1;
    for (int i = 1; i < n; i++) {
        num[i] = num[i - 1] + 1; // @@ [Writing to num[i] where i may exceed array bound of 5 for n>5; buffer overflow]
    }
    permutation(0,n);
    int njj = nj(n);
    for (int i = 0; i < njj; i++) {
        int min = find(njj);
        for (int k = 0; k< n; k++) {
            printf("%d ", numm[min][k]); // @@ [Accessing numm[min][k] where min index may be >=130 (row bound) and k may be >=5 (column bound); out-of-bounds access]
        }printf("\n");
    }

    return 0;
}