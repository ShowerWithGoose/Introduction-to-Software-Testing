#include<stdio.h>
#define MAXN 110
int s[MAXN];
int main() {
	int head=0;
	int opt,num;
	scanf("%d",&opt);
	while(opt!=-1) {
		if(opt) {
			if(head>100)
				printf("error ");
			else {
				scanf("%d",&num);
				s[++head]=num;
			}
		}
		if(!opt) {
			if(!head)
				printf("error ");
			else
				printf("%d ",s[head--]);
		}
		scanf("%d",&opt);
	}
	return 0;
}


