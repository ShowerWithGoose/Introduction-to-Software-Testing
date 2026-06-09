#include <stdio.h>
#define MAXSIZE 100
int main() {
	int a[110], base=0, top=0, op, e;
	while(scanf("%d",&op)!=EOF) {
		if(op==-1) break;
		else if(op==1) {
			scanf("%d",&e);
			if(top-base==MAXSIZE) printf("error "); //栈满不入栈
			else {
				a[top]=e;
				top++;
			}
		} else if(op==0) {
			if(top==base) printf("error ");  //栈空不出栈
			else {
				top--;
				printf("%d ",a[top]);
			}
		}
	}
	return 0;
}

