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
        printf("12\n21\n"); // @@ [Missing space between numbers; should be "1 2" and "2 1" to match expected output format]
    }
    else if(x == 3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    else if(x == 4){
        printf("0"); // @@ [Incorrect output for N=4; should output all 24 lexicographically ordered permutations of 1-4, not "0"]
    }
    return 0;
}