#include<stdio.h>
int num[5],numm[130][5],o,nummflag[130];
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
            numm[o][i] = num[i];
            nummflag[o] =nummflag[o]*10+num[i]; // @@ [nummflag[o] is used uninitialized; it starts with garbage value, leading to incorrect lexicographical ordering]
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
    int min = 999999;
    int i = 0,ko;
    for ( ; i < nj; i++) {
        if (nummflag[i] < min && nummflag[i]>0) { min = nummflag[i]; ko = i; } // @@ [ko may be used uninitialized if no nummflag[i] > 0 is found, causing undefined behavior]
    }nummflag[ko] = 0;
    return ko;
}
int main() {
    int n;
    scanf_s("%d", &n); // @@ [scanf_s is not standard in all C environments (e.g., GCC on Linux); should use scanf for portability, causing compilation error where scanf_s is undefined]
    num[0] = 1;
    for (int i = 1; i < n; i++) {
        num[i] = num[i - 1] + 1;
    }
    permutation(0,n);
    int njj = nj(n);
    for (int i = 0; i < njj; i++) {
        int min = find(njj); // @@ [find returns 'ko' which may be uninitialized; also logic for sorting via numeric encoding fails for N>=10 due to digit collision, but N<=10 so 10 causes two-digit issue]
        for (int k = 0; k< n; k++) {
            printf("%d ", numm[min][k]);
        }printf("\n");
    }

    return 0;
}