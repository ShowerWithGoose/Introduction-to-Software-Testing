#include <stdio.h>
#include <assert.h>
//元素elem进栈
int push(int* a, int top, int elem) {
    a[++top] = elem;
    return top;
}
//数据元素出栈
int pop(int* a, int top) {
    if (top == -1) {
        printf("error ");
        return -1;
    }
    printf("%d ", a[top]);
    top--;
    return top;
}
int main() {
	int n,i = -1;
    int a[200];
	scanf("%d", &n);
	while (n != -1) {
		if (n == 0) {
            i = pop(a, i);
		}
        else if (n == 1) {
            scanf("%d", &n);
            i = push(a, i, n);
        }
        scanf("%d", &n);
	}
	return 0;
}



