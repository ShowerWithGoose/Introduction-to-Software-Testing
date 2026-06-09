#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct zhan {
    int num;
};

int  deleteElem(struct zhan shuzu[], int i, int summ) { //删除
    int k;

    for ( k = i + 1; k < summ; k++ ) { /* 元素依次前移一个位置 */
        shuzu[k - 1].num = shuzu[k].num;
    }

    return 1;                                                     /* 删除成功 */
}

int main() {
    struct zhan shuzu[100];

    int sum = 0;

    int choice;
    int num;

    while (1) {
        scanf("%d", &choice);
        int op = 0;

        if (choice == 0) { //出栈
            scanf("%d", &num); // @@ Error: Pop operation (0) does not take an input value. It should pop the top element of the stack.

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) { // @@ Error: Stack pop should remove the top element (index sum-1), not search for a specific value.
                    if (shuzu[i].num == num) {
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum); // @@ Error: Deleting an arbitrary element by shifting violates LIFO stack property. Should simply decrement sum.
                printf("%d ", num); // @@ Error: Should print the value of the top element being popped, not the input num.
                sum--;
            }
        } else if (choice == 1) { //入栈
            scanf("%d", &num);
            if (sum == 100) {
                printf("error ");
            } else {
                shuzu[sum].num = num;
                sum++;
            }
        } else if (choice == -1) {
            break;
        }
    }

    return 0;
}