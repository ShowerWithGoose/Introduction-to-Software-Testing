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

        if (choice == 0) { //出栈 @@ [The problem requires that '0' alone represents a pop operation, but this code reads an extra integer 'num' after reading 0, which is incorrect. According to the specification, pop operation does not take an additional number.]
            scanf("%d", &num); @@ [This scanf is wrong because pop operation (0) should not be followed by a number to pop; instead, it should pop the top element of the stack.]

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) { @@ [Stacks are LIFO; this linear search for 'num' and deletion from arbitrary position violates stack behavior. The pop operation must remove the last pushed (top) element, not an arbitrary value.]
                    if (shuzu[i].num == num) {
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum); @@ [This function deletes an element at arbitrary index 'op', which is not how a stack works. Stack pop must remove the top element (index sum-1).]
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