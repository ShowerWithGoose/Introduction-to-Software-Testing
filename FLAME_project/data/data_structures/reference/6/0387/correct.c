#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LL long long
int a[11111];
int main() {
	int i=0,n=0,flag;
	int num=0;
	while(scanf("%d",&flag)) {
		if(flag==1) {
			num++;
			if(num>99) {
				printf("error ");
				num=99;
			} else
				scanf("%d",&a[i++]);
		}
		if(flag==0) {
			num--;
			if(num<0) {
				printf("error ");
				num=0;
			} else
				printf("%d ",a[--i]);
		}
		if(flag==-1)
			break;
	}
	return 0;
}

