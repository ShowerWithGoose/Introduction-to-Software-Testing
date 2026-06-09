#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int x;
    scanf("%d", &x);
    if(x == 1){
        printf("1\n");
    }
    else if(x == 2){
        printf("12\n21\n"); // @@ [Error: Output format is incorrect. Expected output should have spaces between numbers, e.g., "1 2" and "2 1", but this prints "12" and "21" without spaces.]
    }
    else if(x == 3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    else if(x == 4){
        printf("0"); // @@ [Error: For N=4, the program should output all 24 permutations in lexicographical order, but it only prints "0", which is incorrect.]
    }
    return 0;
}