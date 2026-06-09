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

        if (choice == 0) { //出栈 @@ [The problem defines '0' as a pop operation that removes the top element of the stack, but this code incorrectly reads an extra integer 'num' and tries to find and remove that specific value from the stack, which is not how a stack works. A stack is LIFO, so pop should remove the last pushed element, not an arbitrary value.]
            scanf("%d", &num); @@ [This scanf is incorrect because pop operation (0) should not be followed by a number in the input. The input format specifies that only push operations (1) are followed by an integer. This causes misreading of the input sequence.]

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) {
                    if (shuzu[i].num == num) {
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum); @@ [This attempts to delete an arbitrary element from the middle of the array, violating stack LIFO behavior. Stack pop must remove the top (last added) element, not search for a value.]
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