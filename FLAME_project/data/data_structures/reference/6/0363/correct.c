#include <stdio.h>
#include <string.h>

#define MAX_N 10010

int opt,c;
int top;
int st[MAX_N];
int main() {
	while(~scanf("%d",&opt)) {
		if(opt==-1) break;
		if(opt==1) {
			scanf("%d",&c);
			if(top==100) {
				printf("error ");
				continue;
			}
			st[++top]=c;
		}
		if(opt==0) {
			if(!top) {
				printf("error ");
				continue;
			}
			printf("%d ",st[top--]);
		}
	}
	return 0;
}

