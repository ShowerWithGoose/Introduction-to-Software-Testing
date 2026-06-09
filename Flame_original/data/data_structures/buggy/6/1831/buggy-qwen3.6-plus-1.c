#include <stdio.h>
#include <stdbool.h>

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
    while (tou >= 0) { // @@ The problem states that after all operations, the stack may not be empty, and does not require popping remaining elements. This loop incorrectly outputs them.
        chu(&yuansu); // @@ Unnecessary pop operation for remaining elements.
        printf("%d ", yuansu); // @@ Incorrectly prints remaining elements, violating the output requirement.
    }
    printf("\n"); // @@ The reference program does not print a newline, and the problem does not require it. This may cause a format mismatch.
    return 0;
}