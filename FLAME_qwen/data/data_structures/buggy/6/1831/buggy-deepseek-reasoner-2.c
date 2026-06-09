#include <stdio.h>
#include <stdbool.h> // @@ Header inclusion is valid, but ensure compiler supports C99 or later.

#define MAX_SIZE 100

int zhan[MAX_SIZE];
int tou = -1; 
bool jin(int yuansu) {
    if (tou >= MAX_SIZE - 1) {
        return false;
    }
    zhan[++tou] = yuansu; 
    return true;
}
bool chu(int *yuansu) {
    if (tou < 0) {
        return false;
    }
    *yuansu = zhan[tou--]; 
    return true;
}

int main() {
    int caozuo, yuansu;
    bool success;

    while (true) {
        scanf("%d", &caozuo);
        
        if (caozuo == -1) {
            break;
        } else if (caozuo == 1) {
            scanf("%d", &yuansu);
            success = jin(yuansu);
            if (!success) {
                printf("error ");
            }
        } else if (caozuo == 0) {
            success = chu(&yuansu);
            if (!success) {
                printf("error ");
            } else {
                printf("%d ", yuansu);
            }
        } else {
            printf("error ");
        }
    }
    while (tou >= 0) { // @@ [Error: Extra loop outputs remaining elements; only pops during operations should be printed as per problem statement.]
        chu(&yuansu); // @@ [Error: This pop is not part of the input operations and will produce incorrect output.]
        printf("%d ", yuansu); // @@ [Error: Printing elements that were not popped during operations.]
    }
    printf("\n"); // @@ [Potential error: Expected output does not specify a trailing newline; reference program does not print one.]
    return 0;
}