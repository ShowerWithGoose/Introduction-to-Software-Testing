#include <stdio.h>

#define MAXSIZE 101

struct zhan {
    int num[MAXSIZE];
    int pointer;
} stem;

int pushzhan(struct zhan *s, int digit) {
    if (s->pointer == MAXSIZE - 1) { // @@ Error: The condition should be s->pointer == MAXSIZE - 1 to check if the stack is full, but the reference program uses s->pointer == MAXSIZE. Since pointer starts at -1 and increments before storing, the maximum valid index is MAXSIZE-1. The reference program's isfull function checks s->pointer == MAXSIZE, which is incorrect because pointer never reaches MAXSIZE; it reaches MAXSIZE-1. This code uses MAXSIZE-1, which is correct for the logic, but the problem states the reference program is correctly implemented, so this change may cause inconsistency. However, the main error is in the quitzhan function.
        printf("error: Stack is full\n"); // @@ Error: The output format should be "error " (with a space after "error"), not "error: Stack is full\n". The problem requires outputting "error" followed by a space, not a full error message.
        return 0;
    }
    s->pointer++;
    s->num[s->pointer] = digit;
    return 1;
}

int quitzhan(struct zhan *s) {
    if (s->pointer == -1) {
        printf("error"); // @@ Error: The output format should be "error " (with a space after "error"), not "error" without a space. The problem requires a space after "error" to match the expected output format.
        return 0;
    }
    int digit = s->num[s->pointer];
    s->pointer--;
    printf("%d ", digit);
    return 1;
}

int main() {
    int op, follow;
    stem.pointer = -1;
    
    while (1) {
        if (scanf("%d", &op) != 1) {
            printf("Invalid input\n"); // @@ Error: The problem does not require handling invalid input with this message. The reference program does not include this check. This extra output will cause mismatch with expected output.
            break;
        }
        
        if (op == -1) {
            break;
        } else if (op == 0) {
            quitzhan(&stem);
        } else if (op == 1) {
            if (scanf("%d", &follow) != 1) {
                printf("Invalid input\n"); // @@ Error: Same as above, unnecessary and incorrect output.
                break;
            }
            pushzhan(&stem, follow);
        }
    }

    printf("\n");
    return 0;
}