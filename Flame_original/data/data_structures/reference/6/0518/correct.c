#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10
struct stack {
	int top;
	int num[10001];
} s;
int i,n,m;
int main() {
	s.top=0;
	while(~scanf("%d",&n)) {
		if(n==1) {
			scanf("%d",&m);
			if(s.top>=100) {
				printf("error ");
			} else {
				s.num[s.top]=m;
				s.top++;
			}
		} else if(n==0) {
			if(s.top<1) {
				printf("error ");
			} else {
			printf("%d ",s.num[s.top-1]);
			s.top--;
		}
		}
		else if(n==-1) {
		break;
	}
	}
	return 0;
}


