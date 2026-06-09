#include<stdio.h>

int main() {
	int top=-1;
	int a[100]= {0};
	int op,n;
	while(1) {
		scanf("%d",&op);
		if(op==-1)
			break;
		if(op==0) {
			if(top<0) {
				printf("error ");
			} else {
				printf("%d ",a[top]);
				a[top--]=0;
			}
		}
		if(op==1) {
			scanf("%d",&n);
			if(top>99) {
				printf("error ");
			} else {
				a[++top]=n;
			}
		}
	}

	return 0;
}

