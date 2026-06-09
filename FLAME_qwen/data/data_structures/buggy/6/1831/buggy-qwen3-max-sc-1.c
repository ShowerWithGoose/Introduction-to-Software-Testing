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
    while (tou >= 0) {
        chu(&yuansu);
        printf("%d ", yuansu);
    } @@ [The problem states that only popped elements during pop operations should be output. This extra loop prints remaining stack elements after -1, which is incorrect behavior and causes wrong output.]
    printf("\n"); @@ [The problem requires output only the popped elements separated by spaces with a space after the last element, and no newline. Printing a newline here violates the output format.]
    return 0;
}