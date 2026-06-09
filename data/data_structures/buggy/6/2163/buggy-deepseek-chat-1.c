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
            scanf("%d", &num); // @@ [Error: The pop operation (0) should not read an additional integer. According to the problem, only push (1) is followed by an integer; pop (0) just pops the top element. Reading an extra integer here will consume the next operation code or data, causing incorrect parsing.]

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) {
                    if (shuzu[i].num == num) { // @@ [Error: The pop operation should pop the top element (last pushed), not search for a specific value. The problem specifies a standard stack (LIFO), so you should always pop the most recently added element, not one matching a given number.]
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum); // @@ [Error: Using an array shift to "pop" is incorrect for a stack. A stack should only remove the top element (last index), not shift all elements. This also makes the operation O(n) instead of O(1).]
                printf("%d ", num);
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