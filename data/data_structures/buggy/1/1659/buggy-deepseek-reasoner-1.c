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
        printf("12\n21\n"); @@ // Error: missing spaces between numbers; should be "1 2\n2 1\n"
    }
    else if(x == 3){
        printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1\n");
    }
    else if(x == 4){ @@ // Error: condition fails to handle N>4; missing permutations for N=5..10
        printf("0"); @@ // Error: incorrect output for N=4; should output all 24 permutations of 1..4
    }
    return 0;
}