/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。
int main() {
    int a[100], op, n;
    int rear = 100 - 1, front = 0, total = 0;
    while (scanf("%d", &op) != EOF) {
        switch (op)
        {
        case 1:
            scanf("%d", &n);
            if (total >= 100) {
                printf("error ");
                break;
            }
            rear = (++rear) % 100;
            a[rear] = n;
            total++;
            break;
        case 0:
            if(total <= 0) {
printf("error ");break;
            }
                

            else 
                printf("%d ",a[rear]);
            total--;
            rear = (rear + 99) % 100;
            break;
        case -1:
            return 0;
        }
    }
    system("pause");
    return 0;
}


