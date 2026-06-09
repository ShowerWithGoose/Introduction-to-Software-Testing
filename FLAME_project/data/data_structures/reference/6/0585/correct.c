#include<stdio.h>
int main() {
	int n,m,count=-1;
	int score[100];
	while(scanf("%d",&n)) {
		if(n==-1) break;
		if(n==1) {
			scanf("%d ",&m);
			if(count<100) {
				count++;
				score[count]=m;
			} 
			else printf("error ");
		}
		if(n==0) {
			if(count<0) printf("error ");
			else {
				printf("%d ",score[count]);
				count--;
			}
		}
	}
	return 0;
}



