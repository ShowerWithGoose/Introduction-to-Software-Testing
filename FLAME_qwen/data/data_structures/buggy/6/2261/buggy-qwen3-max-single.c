#include <stdio.h>

#define MAXSIZE 101

struct zhan {
    int num[MAXSIZE];
    int pointer;
} stem;

int pushzhan(struct zhan *s, int digit) {
    if (s->pointer == MAXSIZE - 1) {
        printf("error: Stack is full\n"); // @@ [The problem expects "error " (without colon, newline, or extra text). This format mismatch causes incorrect output.]
        return 0;
    }
    s->pointer++;
    s->num[s->pointer] = digit;
    return 1;
}

int quitzhan(struct zhan *s) {
    if (s->pointer == -1) {
        printf("error"); // @@ [The problem expects "error " (with a trailing space), but this prints "error" without space, causing format mismatch in output.]
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
            printf("Invalid input\n"); // @@ [The problem does not mention handling invalid input; printing "Invalid input" deviates from expected behavior and may cause wrong output.]
            break;
        }
        
        if (op == -1) {
            break;
        } else if (op == 0) {
            quitzhan(&stem);
        } else if (op == 1) {
            if (scanf("%d", &follow) != 1) {
                printf("Invalid input\n"); // @@ [Same as above: handling non-integer input is not part of the problem spec; this leads to unexpected output.]
                break;
            }
            pushzhan(&stem, follow);
        }
    }

    printf("\n");
    return 0;
}