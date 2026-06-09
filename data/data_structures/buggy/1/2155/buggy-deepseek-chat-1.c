#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1");
    if (n == 2)
        printf("1 2\n2 1");
    if (n == 3)
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
    if (n == 4)
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n"); // @@ Missing handling for n=5 and n>4. The program only handles n up to 4, but the problem requires handling N up to 10. For n=5, no output is produced, and for n>4, the program prints nothing or incorrect output. Additionally, the program lacks a general algorithm for arbitrary N, relying on hardcoded strings which is incomplete.

}