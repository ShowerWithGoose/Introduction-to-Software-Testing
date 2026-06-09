#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
int a[101],len,op,t;
int main() {
	len=0;
	while(scanf("%d",&op)) {
		if(op==-1)
			return 0;
		if(op==1) {
			scanf("%d",&t);
			if(len==100) {
				printf("error ");
				continue;
			}
			len++;
			a[len]=t;
		}

		if(op==0) {
			if(len==0) {
				printf("error ");
				continue;
			} else {
				printf("%d ",a[len]);
				len--;
			}
		}
	}
	return 0;
}



