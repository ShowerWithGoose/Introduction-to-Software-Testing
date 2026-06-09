#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LL long long
struct cc {
	int p;
	int q;
};
int i=0,n=0;
int j=0;
	struct cc a[1111];
	struct cc b[1111];
	struct cc c[1111];
	struct cc max;
void px(struct cc *c,int t) {

	for(i=0; i<t; i++) {
		for(j=0; j<t-i; j++) {
			if(c[j].q<c[j+1].q) {
				max = c[j];
				c[j]=c[j+1];
				c[j+1]=max;
			}
		}
	}
}
int main() {


	do {
		scanf("%d%d",&a[n].p,&a[n].q);
		n++;
	} while(getchar()!='\n');
	int m=0;
	while(scanf("%d%d",&b[m].p,&b[m].q)!=EOF) {
		m++;
	}
	int t=0;
	for(i=0; i<n; i++) {
//		printf("%d %d\n",a[i].p,a[i].q);
//		printf("%d %d\n",b[i].p,b[i].q);

		for(j=0; j<m; j++) {
			c[t].p=a[i].p*b[j].p;
			c[t].q=a[i].q+b[j].q;
			t++;
		}
	}

	for(i=0; i<t; i++) {
		for(j=i+1; j<t; j++) {
			if(c[j].q==c[i].q) {
			
				c[i].p+=c[j].p;
				c[j].p=0;
				c[j].q=0;
			}
			//	c[j]= {0,0};
		}
	}
px(c,t);


	for(i=0; i<t; i++)
		if(c[i].q!=0||c[i].p!=0)
			printf("%d %d ",c[i].p,c[i].q);
	return 0;
}


