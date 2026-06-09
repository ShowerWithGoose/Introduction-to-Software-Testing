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
    
    
    for (int i = num1; i <= num2; i++) {
        swap(&a[num1], &a[i]);
        F(a, num1 + 1, num2);
        swap(&a[num1], &a[i]); 
    }
}

int main() {
    int N;
    scanf("%d", &N);
    if(N!=3&&N!=4) // @@ This condition incorrectly excludes N=3 and N=4 from the general permutation algorithm, but the hardcoded outputs for N=3 and N=4 have formatting issues (missing newline at end for N=3, and the algorithm itself should handle all N values uniformly).
    {
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    

    F(a, 0, N - 1);
    }
    if(N==3)
    {
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1 "); // @@ The output ends with a space instead of a newline, which does not match the expected format of each permutation on its own line.
    }
    if(N==4)
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1"); // @@ This hardcoded output is correct for N=4, but the approach is not general and violates the requirement to generate permutations algorithmically for all N.
    }
    return 0;
}