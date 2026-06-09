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

        if (choice == 0) { //出栈 @@ [The program incorrectly reads an extra integer 'num' for pop operation (0), but pop should not take any value. This causes misalignment in input parsing and leads to infinite loop or wrong behavior.]
            scanf("%d", &num); @@ [Pop operation (0) should not read a number; this consumes the next operation/value as 'num', causing logic errors and potential infinite loops.]

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) { @@ [Stack is LIFO, but this searches for 'num' anywhere in the array, violating stack semantics. It should only pop the top element.]
                    if (shuzu[i].num == num) {
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum); @@ [This deletes an arbitrary element instead of popping the top, which breaks stack behavior. Also, shifting elements is unnecessary for a stack.]
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