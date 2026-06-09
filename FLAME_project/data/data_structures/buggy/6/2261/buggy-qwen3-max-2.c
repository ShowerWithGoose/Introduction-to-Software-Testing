#include <stdio.h>

#define MAXSIZE 101

struct zhan {
    int num[MAXSIZE];
    int pointer;
} stem;

int pushzhan(struct zhan *s, int digit) {
    if (s->pointer == MAXSIZE - 1) {
        printf("error: Stack is full\n"); // @@ [The error message format is incorrect. It should print "error " (without colon, newline, or extra text) to match expected output format.]
        return 0;
    }
    s->pointer++;
    s->num[s->pointer] = digit;
    return 1;
}

int quitzhan(struct zhan *s) {
    if (s->pointer == -1) {
        printf("error"); // @@ [Missing a space after "error". The expected output requires "error " (with trailing space), but this prints "error" without space, causing concatenation with next output like "error8".]
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
            printf("Invalid input\n"); // @@ [This error handling is not part of the problem specification and may cause wrong output format. The problem assumes valid input, so printing "Invalid input" leads to unexpected output.]
            break;
        }
        
        if (op == -1) {
            break;
        } else if (op == 0) {
            quitzhan(&stem);
        } else if (op == 1) {
            if (scanf("%d", &follow) != 1) {
                printf("Invalid input\n"); // @@ [Same as above: this extra error message is not required by the problem and violates output format expectations.]
                break;
            }
            pushzhan(&stem, follow);
        }
    }

    printf("\n");
    return 0;
}