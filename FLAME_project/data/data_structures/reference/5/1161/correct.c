#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
struct mu {
	int pow;
	int xs;
} a[10001],b[10001],ans[20002];
int fi(const void *p1,const void *p2) {
	struct mu *m=(struct mu *)p1;
	struct mu *n=(struct mu *)p2;
	return n->pow-m->pow;
}
int i,j,l,la,lb,k,po,x,flag;
char c;
int main() {
	i=1;
	while(scanf("%d %d",&a[i].xs,&a[i].pow)) {
		c=getchar();
		if(c=='\n')
			break;
		i++;
	}
	la=i,i=1;
	while(scanf("%d %d",&b[i].xs,&b[i].pow)) {
		c=getchar();
		if(c!=' ')
			break;
		i++;
	}
	lb=i;
	l=0;
	for(i=la; i>=1; i--) {
		for(j=lb; j>=1; j--) {
			po=a[i].pow+b[j].pow;
			x=a[i].xs*b[j].xs;
			flag=0;
			for(k=1; k<=l; k++) {
				if(ans[k].pow==po) {
					flag=1;
					break;
				}
			}
			if(!flag) {
				l++;
				ans[l].pow=po;
				ans[l].xs=x;
			} else {
				ans[k].xs+=x;
			}
		}
	}
	qsort(ans+1,l,sizeof(struct mu),fi);
	for(i=1; i<=l; i++) {
		printf("%d %d ",ans[i].xs,ans[i].pow);
	}
	return 0;
}



