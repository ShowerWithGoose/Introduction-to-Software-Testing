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
            scanf("%d", &num); // @@ [Error: The pop operation (choice == 0) should not read an additional integer. The problem specifies that '0' alone represents a pop, but this code incorrectly reads a value 'num' after '0', causing the program to consume the next input (e.g., '567' in the test case) as 'num', leading to incorrect behavior and potential infinite loop or wrong output.]

            if (sum == 0) {
                printf("error ");
            } else {
                for (int i = 0; i < sum; i++) {
                    if (shuzu[i].num == num) {
                        op = i;
                        break;
                    }
                }
                deleteElem(shuzu, op, sum);
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