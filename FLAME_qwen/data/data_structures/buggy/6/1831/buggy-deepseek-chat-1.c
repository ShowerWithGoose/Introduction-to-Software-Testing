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
            printf("error "); // @@ This line incorrectly prints "error " for invalid operations (e.g., input like 2, 3, etc.), but the problem specification only defines operations 1, 0, and -1. The reference program does not handle invalid operations, so this extra output causes a mismatch with expected output.
        }
    }
    while (tou >= 0) { // @@ This loop pops and prints remaining elements after the -1 sentinel, but the problem specification does not require this. The reference program does not output remaining stack contents, so this adds extra output.
        chu(&yuansu);
        printf("%d ", yuansu);
    }
    printf("\n"); // @@ This prints a newline at the end, but the expected output format does not include a trailing newline. The reference program does not print a newline.
    return 0;
}