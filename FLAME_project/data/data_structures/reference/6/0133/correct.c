#include<stdio.h>
#define MAX 100
int stack[MAX];
int Top=-1;
void push(int a[],int item) {
	if(Top==MAX-1) printf("error ");
	else a[++Top]=item;
}
void pop(int a[]) {
	if(Top==-1) printf("error ");
	else printf("%d ",a[Top--]);
}
int main() {
	int num,op;
	while(~scanf("%d",&op)) {
		if(op==1) {
			scanf("%d",&num);
			push(stack,num);
		}
		else if(op==0) {
			pop(stack);
		}
		else if(op==-1) break;
	}
	return 0;
}

