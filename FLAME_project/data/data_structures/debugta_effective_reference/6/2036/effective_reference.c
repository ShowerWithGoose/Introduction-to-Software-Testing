#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ll long long
#define eps 1e-6
#define MAX 1000005
int main() {
	int a[105]= {0};
	int top=-1;
	int n,m;
	while(~scanf("%d",&n)) {

		if(n==1) {
			scanf("%d",&m);
			if (top == 99)
				printf("error ");
			else {
				top++;
				a[top]=m;
			}
		} else if(n==0) {
			if(top==-1) printf("error ");
			else {
				printf("%d ",a[top]);
				top--;
			}
		} else break;
	}
	return 0;
}


