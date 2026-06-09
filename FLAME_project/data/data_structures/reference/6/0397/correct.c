#include <stdio.h>
#include <string.h>
#define MAXN 110
typedef struct _stack {
	int size;
	int curr;
	int data[MAXN];
} Stack;
typedef Stack* PStack;
void Push(int val, PStack stk) {
	if (stk->curr == stk->size) printf("error ");
	else stk->data[++stk->curr] = val;
	
}
void Pop(PStack stk) {
	if (stk->curr == 0) printf("error ");
	else printf("%d ", stk->data[stk->curr--]);
}
int main() {
//	freopen("SO_INPUT.txt", "r", stdin);
	Stack s1;
	s1.size = 100;
	s1.curr = 0;
	memset(s1.data, 0, MAXN * sizeof(int));
	int op, tmp;
	scanf("%d", &op);
	while (op != -1) {
		if (op == 1) {
			scanf("%d", &tmp);
			Push(tmp, &s1);
		} else if (op == 0) {
			Pop(&s1);
		}
		scanf("%d", &op);
	}
	return 0;
}

