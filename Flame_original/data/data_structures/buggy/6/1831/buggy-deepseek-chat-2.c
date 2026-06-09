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
            printf("error "); // @@ This line incorrectly prints "error " for any invalid operation code, but the problem only defines 1, 0, and -1; however, the reference program does not handle this case, so this is an extra behavior not required by the problem.
        }
    }
    while (tou >= 0) { // @@ This loop pops and prints remaining elements after the end of operations, but the problem statement says "After all operations have been performed, the stack may not be empty" and the output should only be the sequence of popped elements during operations, not the remaining stack contents. The reference program does not have this loop.
        chu(&yuansu);
        printf("%d ", yuansu);
    }
    printf("\n"); // @@ This prints a newline at the end, but the expected output format does not specify a newline; the reference program does not print a newline.
    return 0;
}