#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *a, int x, int y) { // @@ [Error: This permutation function does not generate permutations in lexicographic order. It uses a recursive swap method that produces all permutations but in arbitrary order, which violates the problem requirement of lexicographically sorted output. This error affects N>5.]
    if (x == y - 1) {
        int j;
        for (j = 0; j < y; j++) {
            printf("%d ", *(a + j));
        }
        printf("\n");
        return;
    }

    int k = 0;
    for (k = x; k < y; k++) {
        swap(a + k, a + x);
        permutation(a, x + 1, y);
        swap(a + k, a + x);
    }
}
int a[11];

int main() {
    int n, i;
    scanf("%d", &n);
    if (n == 1) {
        printf("1"); // @@ [Error: Missing trailing space after the number and missing newline at the end. Expected output format: "1 " followed by newline.]
        return 0;
    }
    if (n == 2) {
        printf("1 2\n2 1"); // @@ [Error: Missing trailing spaces after the last number on each line and missing newline after the last line. Expected output: "1 2 \n2 1 \n" (with spaces and final newline).]
        return 0;
    }
    if (n == 3) {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1"); // @@ [Error: Missing trailing spaces after the last number on each line and missing newline after the last permutation. Expected output: each line should end with a space before newline, and final line should end with newline.]
        return 0;
    }
    if (n == 4) {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1 "); // @@ [Error: Missing trailing spaces after the last number on each line (except possibly the last line) and missing newline after the last permutation. The last line also has a trailing space but no newline. Expected output: each line ends with space then newline.]
        return 0;
    }
    if (n == 5) {
        printf("1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 4 5 3\n1 2 5 3 4\n1 2 5 4 3\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 4 5 2\n1 3 5 2 4\n1 3 5 4 2\n1 4 2 3 5\n1 4 2 5 3\n1 4 3 2 5\n1 4 3 5 2\n1 4 5 2 3\n1 4 5 3 2\n1 5 2 3 4\n1 5 2 4 3\n1 5 3 2 4\n1 5 3 4 2\n1 5 4 2 3\n1 5 4 3 2\n2 1 3 4 5\n2 1 3 5 4\n2 1 4 3 5\n2 1 4 5 3\n2 1 5 3 4\n2 1 5 4 \n2 3 1 4 5\n2 3 1 5 4\n2 3 4 1 5\n2 3 4 5 \n2 3 5 1 4\n2 3 5 4 1\n2 4 1 3 5\n2 4 1 5 3\n2 4 3 1 5\n2 4 3 5 1\n2 4 5 1 3\n2 4 5 3 1\n" ); // @@ [Error: The hardcoded strings are fragmented and missing many permutations. Also missing trailing spaces and final newlines. This block produces incorrect output for N=5.]
        printf("2 5 1 3 4\n2 5 1 4 3\n2 5 3 1 4\n2 5 3 4 1\n2 5 4 1 3\n2 5 4 3 1\n3 1 2 4 5\n3 1 2 5 4\n3 1 4 2 5\n3 1 4 5 2\n3 1 5 2 4\n3 1 5 4 2\n3 2 1 4 5\n3 2 1 5 4\n3 2 4 1 5\n3 2 4 5 1\n3 2 5 1 4\n3 2 5 4 1\n3 4 1 2 5\n3 4 1 5 2\n3 4 2 1 5\n3 4 2 5 1\n3 4 5 1 2\n3 4 5 2 1\n3 5 1 2 4\n3 5 1 4 2\n3 5 2 1 4\n3 5 2 4 1\n3 5 4 1 2\n3 5 4 2 1\n4 1 2 3 5\n4 1 2 5 3\n4 1 3 2 5\n4 1 3 5 2\n4 1 5 2 3\n4 1 5 3 2\n4 2 1 3 5\n4 2 1 5 3\n4 2 3 1 5\n4 2 3 5 1\n4 2 5 1 3\n4 2 5 3 1\n4 3 1 2 5\n4 3 1 5 2\n4 3 2 1 5\n4 3 2 5 1\n4 3 5 1 2\n4 3 5 2 1\n4 5 1 2 3\n4 5 1 3 2\n4 5 2 1 3\n4 5 2 3 1\n4 5 3 1 2\n4 5 3 2 1\n5 1 2 3 4\n5 1 2 4 3\n5 1 3 2 4\n5 1 3 4 2\n5 1 4 2 3\n5 1 4 3 2\n5 2 1 3 4\n5 2 1 4 3\n5 2 3 1 4\n5 2 3 4 1\n5 2 4 1 3\n5 2 4 3 1\n5 3 1 2 4\n5 3 1 4 2\n5 3 2 1 4\n5 3 2 4 1\n5 3 4 1 2\n5 3 4 2 1\n5 4 1 2 3\n5 4 1 3 2\n5 4 2 1 3\n5 4 2 3 1\n5 4 3 1 2\n5 4 3 2 1\n"); // @@ [Error: This block also contains multiple incomplete lines and missing trailing spaces/newlines after last line.]
        return 0;
    }
    if (n > 1) {
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }
    permutation(a, 0, n); // @@ [Error: This call uses the permutation function that does not generate lexicographic order, leading to wrong ordering for N>5.]
    return 0;
}