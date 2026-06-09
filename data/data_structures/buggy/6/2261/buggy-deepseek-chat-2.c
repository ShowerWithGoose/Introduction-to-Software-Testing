#include <stdio.h>

#define MAXSIZE 101

struct zhan {
    int num[MAXSIZE];
    int pointer;
} stem;

int pushzhan(struct zhan *s, int digit) {
    if (s->pointer == MAXSIZE - 1) { // @@ Error: The condition should be s->pointer == MAXSIZE - 1 to check if the stack is full, but the original reference program uses s->pointer == MAXSIZE. Since pointer starts at -1 and increments before storing, the maximum valid index is MAXSIZE-1. However, the reference program defines MAXSIZE as 101 and checks s->pointer == MAXSIZE, which is incorrect because pointer never reaches MAXSIZE (it goes from -1 to 100 at most). The correct check should be s->pointer == MAXSIZE - 1, but the problem states the stack has max capacity 100, so MAXSIZE should be 100, not 101. The error here is that the condition uses MAXSIZE - 1, which allows pushing when pointer is 100 (i.e., 101 elements), exceeding the capacity of 100. The reference program uses MAXSIZE = 101 and checks s->pointer == MAXSIZE, which is also wrong but in a different way. The correct fix would be to set MAXSIZE to 100 and check s->pointer == MAXSIZE - 1, but since we cannot change the structure, the condition should be s->pointer == MAXSIZE - 1 to match the intended capacity of 100 (since pointer starts at -1, after 100 pushes pointer becomes 99, and the next push would make it 100, which is out of bounds for num[100] if MAXSIZE is 101? Actually num has size 101, indices 0-100, so pointer can go up to 100, meaning 101 elements. The problem says max capacity 100, so MAXSIZE should be 100, but it's 101. The error is that the condition allows overflow. The reference program's isfull checks s->pointer == MAXSIZE, which would never be true because pointer max is 100 when MAXSIZE=101, so it never detects full. This is a logical error.)
        printf("error: Stack is full\n");
        return 0;
    }
    s->pointer++;
    s->num[s->pointer] = digit;
    return 1;
}

int quitzhan(struct zhan *s) {
    if (s->pointer == -1) {
        printf("error"); // @@ Error: The output should be "error " (with a space after error) according to the problem description. The reference program prints "error " with a space. Here it prints "error" without a space, which will cause incorrect output format.
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
            printf("Invalid input\n");
            break;
        }
        
        if (op == -1) {
            break;
        } else if (op == 0) {
            quitzhan(&stem);
        } else if (op == 1) {
            if (scanf("%d", &follow) != 1) {
                printf("Invalid input\n");
                break;
            }
            pushzhan(&stem, follow);
        }
    }

    printf("\n");
    return 0;
}