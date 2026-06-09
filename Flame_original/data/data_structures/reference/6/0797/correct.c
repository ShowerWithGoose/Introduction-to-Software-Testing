#include <stdio.h>
int stck[100];
int top;
int main() {
    int op, num;
    while(scanf("%d", &op) != -1) {
        switch(op) {
            case 1:
                if(top == 100) {
                    scanf("%d", &num);
                    printf("error ");
                    break;
                }
                else {
                    scanf("%d", &num);
                    stck[top++] = num;
                    break;
                }
            case 0:
                if(top == 0) {
                    printf("error ");
                    break;
                }
                else {
                    printf("%d ", stck[--top]);
                    break;
                }
        }
    }

    return 0;
}

