#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*p1,const void*p2);
struct ex{
	int coe;
	int pow;
};
struct ex a[1000],b[1000],c[1000],d[1000];

int main() {
	int n1=0,n2=0;
	int k=0;
	char ch;
	do{
		scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&ch);
		n1++;
	}while(ch!='\n');
	do{
		scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&ch);
		n2++;
	}while(ch!='\n');
	for(int i=0;i<n1;i++) {
		for(int j=0;j<n2;j++) {
			c[k].coe=a[i].coe*b[j].coe;
			c[k].pow=a[i].pow+b[j].pow;
			k++;
		}
	}
	qsort(c,k,sizeof(struct ex),cmp);
	for(int i=0;i<k-1;i++) {
		if(c[i].pow==c[i+1].pow) {
			c[i+1].coe+=c[i].coe;
			c[i].coe=0;
		}
	}
	
	for(int i=0;i<k;i++) {
		if(c[i].coe!=0) {
			printf("%d %d ",c[i].coe,c[i].pow);
		}	
	}	
	return 0;
	
}



int cmp(const void*p1,const void*p2)
{
	struct ex *a=(struct ex*)p1;
	struct ex *b=(struct ex*)p2;
	return b->pow-a->pow;
}

