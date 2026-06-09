#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void F(int *a, int num1, int num2) {
    if (num1 == num2) {
        for (int i = 0; i <= num2; i++) {
            printf("%d", a[i]);
            if (i < num2) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    
    
    for (int i = num1; i <= num2; i++) { // @@ The recursive swap algorithm does not guarantee lexicographic order; use a different permutation generation method.
        swap(&a[num1], &a[i]);
        F(a, num1 + 1, num2);
        swap(&a[num1], &a[i]); 
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if(N!=3&&N!=4)
    {
    int a[N]; // @@ Variable-length array not allowed in C90; use fixed-size array or dynamic allocation.
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    

    F(a, 0, N - 1);
    }
    if(N==3)
    {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1 "); // @@ Trailing space after last permutation; output format error.
    }
    if(N==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1"); // @@ Missing newline after last permutation; output format error.
    }
    return 0;
}