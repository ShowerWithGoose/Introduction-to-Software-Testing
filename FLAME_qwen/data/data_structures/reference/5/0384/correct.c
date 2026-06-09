#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cnm {
	int coe;
	int pow;
};
struct cnm a[66666],b[66666],p[66666],q[66666];
int cmp(const void*a,const void*b) {
	struct cnm*c=(struct cnm*)a;
	struct cnm*d=(struct cnm*)b;
	if(c->pow>d->pow) return -1;
	else return 1;
}
int main() {
	char c=' ';
	int count1=0,count2=0,count3=0,count4=0;
	while(c!='\n') {
		scanf("%d%d%c",&a[count1].coe,&a[count1].pow,&c);
		count1++;
	}
	c=' ';
	while(c!='\n') {
		scanf("%d%d%c",&b[count2].coe,&b[count2].pow,&c);
		count2++;
	}
	int i,j;
	for(i=0; i<count1; i++)
		for(j=0; j<count2; j++) {
			p[count3].coe=a[i].coe*b[j].coe;
			p[count3].pow=a[i].pow+b[j].pow;
			count3++;
		}
	qsort(p,count3,sizeof(p[0]),cmp);

	for(i=0; i<(count3-1); i++) {
		if(p[i].pow==p[i+1].pow) {
			p[i+1].coe=p[i+1].coe+p[i].coe;
			p[i].coe=0;
		}
	}
	for(i=0; i<count3; i++)
		if(p[i].coe!=0)
			printf("%d %d ",p[i].coe,p[i].pow);
	return 0;
}

