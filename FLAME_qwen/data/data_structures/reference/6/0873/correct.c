#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define Maxlen 1//链式存储的串单个链接的字节
#define Maxsize 100
int main() {
    int num;
    int op;
    int top = 0;
    int data[105]={0};
    while (scanf("%d", &op) != EOF) {
        if (op == -1)
            break;
        if (op == 1) {
            scanf("%d", &num);
            if (top >= 100)
                printf("error ");
            else {
                top++;
                data[top] = num;
                
            }
        }
        if (op == 0) {
            if(top==0)
                printf("error ");
            else{
                printf("%d ", data[top]);
                top--;
            }
        }
    }

    return 0;
}

