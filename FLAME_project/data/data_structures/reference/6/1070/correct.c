#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	int *data;
	int top;
}stack;

stack *init_stack() {
	stack *p = (stack *) malloc (sizeof(stack));
	p->data = (int *) malloc (sizeof(int) * 1000);
	p->top = -1;
	return p;
}

void push(stack *s, int val) {
	s->top++;
	s->data[s->top] = val;
	return ;
}

void pop(stack *s) {
	s->top--;
	return ;
}

int empty(stack *s) {
	if(s->top < 0) return 1;
	return 0;
}

int top(stack *s) {
	return s->data[s->top];
}

int main()
{
	stack *s = init_stack();
	int op, val;
	scanf("%d", &op);
	while(op != -1) {
		switch (op) {
			case 1:{
				scanf("%d", &val);
				push(s, val);
				break;
			}
			case 0:{
				if(empty(s)){
					printf("error ");
				}
				else {
					printf("%d ", top(s));
					pop(s);
				}
				break;
			}
		}
		scanf("%d", &op);
	}
	return 0;
}

