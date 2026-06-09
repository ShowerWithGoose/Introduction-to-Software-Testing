#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int stack[100]= {0},top=0;
void in (int a) {
	if(top<100)
		stack[top++]=a;
	else printf("error ");
	}
void out () {
	if(top>0)
		printf("%d ",stack[--top]);
	else
		printf("error ");
}
int main() {
	int x,n;
	while(scanf("%d",&x)!=EOF) {
		if(x==-1)
			break;
		else if(x==1) {
			scanf("%d",&n);
			in(n);
		}
		else if(x==0)
		out();
	}
	return 0;
}

