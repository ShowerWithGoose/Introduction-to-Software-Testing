//
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int a[500];
	int b1=0;
	int b2[105];
	int i,j;
	scanf("%d",&a[0]);
	if(a[0]==0)
		printf("error");
	for(i=1; i<500; i++) {
		scanf("%d",&a[i]);
		if(a[i-1]==1) {
			b1++;
			b2[b1]=a[i];
		} else if(a[i-1]==0) {
			if(b1>0) {
				printf("%d ",b2[b1]);
				b1--;
			} else if(b1==0)
				printf("error ") ;
		}
		if(a[i]==-1)
			break;
	}
	return 0;
}





