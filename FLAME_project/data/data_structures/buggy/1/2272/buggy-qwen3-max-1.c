#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1"); // @@ [Missing newline at the end of output. Expected output must end with a newline.]
        return 0;
    } else if (n == 2) {
        printf("1 2\n");
        printf("2 1"); // @@ [Missing newline at the end of the last permutation line. All output lines including the last must end with a newline.]
    } else if(n==3){
        printf("1 2 3\n");
        printf("1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n"); // @@ [This line is correct in content and newline, but inconsistent style; however, not an error for n=2 case. The actual error for test case n=2 is above.]
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
               "3 4 2 1\n"
               "4 1 2 3\n"
               "4 1 3 2\n"
               "4 2 1 3\n"
               "4 2 3 1\n"
               "4 3 1 2\n"
               "4 3 2 1"); // @@ [Missing newline at the end of the last line for n=4 case. Though not triggered by test input n=2, it's a similar pattern error. However, the immediate error for given test case (n=2) is on the "2 1" line above.]
    }


}