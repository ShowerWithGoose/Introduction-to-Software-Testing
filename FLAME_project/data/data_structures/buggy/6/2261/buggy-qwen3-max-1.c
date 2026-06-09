#include <stdio.h>

#define MAXSIZE 101

struct zhan {
    int num[MAXSIZE];
    int pointer;
} stem;

int pushzhan(struct zhan *s, int digit) {
    if (s->pointer == MAXSIZE - 1) {
        printf("error: Stack is full\n"); // @@ [The error message format is incorrect. It should output "error " (without colon, newline, or extra text) to match expected output format.]
        return 0;
    }
    s->pointer++;
    s->num[s->pointer] = digit;
    return 1;
}

int quitzhan(struct zhan *s) {
    if (s->pointer == -1) {
        printf("error"); // @@ [Missing trailing space after "error". Expected output requires "error " with a space to separate from next output.]
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
            printf("Invalid input\n"); // @@ [This check and message are not part of the problem specification and may interfere with expected behavior on valid inputs. However, since test input is valid, this line doesn't trigger in the given test case. But strictly speaking, problem doesn't require handling non-integer input, so this is extraneous and could cause issues in other contexts. However, the primary errors are in the two print statements above.]
            break;
        }
        
        if (op == -1) {
            break;
        } else if (op == 0) {
            quitzhan(&stem);
        } else if (op == 1) {
            if (scanf("%d", &follow) != 1) {
                printf("Invalid input\n"); // @@ [Same as above: unnecessary input validation not required by problem spec. But again, not triggered in given test case. Main bugs are in error message formatting in pushzhan and quitzhan.]
                break;
            }
            pushzhan(&stem, follow);
        }
    }

    printf("\n");
    return 0;
}