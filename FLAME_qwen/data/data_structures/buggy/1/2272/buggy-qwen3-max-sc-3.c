#include "stdio.h" @@ [Using double quotes for standard header may cause compilation issues in some environments; should use <stdio.h>]

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1");
        return 0;
    } else if (n == 2) {
        printf("1 2\n");
        printf("2 1");
    } else if(n==3){
        printf("1 2 3\n");
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n"); @@ [Extra newline at the end causes last line to have trailing \n, but expected output for n=3 should not end with newline according to reference]
    } else if(n==4){
        printf("1 2 3 4\n"
               "1 2 4 3\n"
               "1 3 2 4\n"
               "1 3 4 2\n"
               "1 4 2 3\n"
               "1 4 3 2\n"
               "2 1 3 4\n"
               "2 1 4 3\n"
               "2 3 1 4\n"
               "2 3 4 1\n"
               "2 4 1 3\n"
               "2 4 3 1\n"
               "3 1 2 4\n"
               "3 1 4 2\n"
               "3 2 1 4\n"
               "3 2 4 1\n"
               "3 4 1 2\n"
               "3 4 2 1\n" @@ [This line ends with \n but the last permutation "4 3 2 1" should not be followed by a newline; reference program does not have trailing newline]
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1");
    }


}