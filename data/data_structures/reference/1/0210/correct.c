#include <stdio.h>

int loc = 1;
int hash[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void print() {
    int i = 0;
    for (; i < loc; i++) {
        printf("%d ", hash[i]);
    }
    puts("");
}

void swap(int a, int b) {
    int temp = hash[a];
    hash[a] = hash[b];
    hash[b] = temp;
    return;
}

void solve(int n) {
    if (n == 2) {
        print();
        swap(loc - 1, loc - 2);
        print();
        swap(loc - 1, loc - 2);
        return;
    }
    solve(n - 1);
    int i = 1;
    for (; i < n; i++) {
        int j = i;
        for (; j > 0; j--) {
            swap(loc - n + j, loc - n + j - 1);
        }
        solve(n - 1);
        for (; j < i; j++) {
            swap(loc - n + j, loc - n + j + 1);
        }
    }
    return;
}

int main() {
    scanf("%d", &loc);
    if (loc == 1) {
        printf("1");
        return 0;
    }
    solve(loc);
    return 0;
}


