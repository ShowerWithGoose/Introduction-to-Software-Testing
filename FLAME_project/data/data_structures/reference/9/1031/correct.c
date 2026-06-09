#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct l {
	int a,b,c,d;
} st[100+10];
int cmp(const void*a,const void*b) {
	struct l *m=(struct l *)a;
	struct l *n=(struct l *)b;
	if(m->a>n->a) {
		return 1;
	} else {
		return -1;
	}
}
int main() {
	int n,i,j,num[100+10];
	for(i=0;i<110;i++){
		num[i]=1;
	}
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&st[i].a,&st[i].b,&st[i].c,&st[i].d);
	}
	int k;
	qsort(st,n,sizeof(struct l),cmp);
	for(i=0; i<n; i++) {
		k=i;
		j=k+1;
		while(k<n&&j<n) {
			for(j=k+1; j<n; j++) {
				if(st[j].a==st[k].c&&st[k].d==st[j].b) {
					num[i]++;
					break;
				}
			}
			k=j;
			j++;
		}
	}
	int max=0,maxi=0;
	for(i=0; i<n; i++) {
		if(num[i]>max) {
			max=num[i];
			maxi=i;
		}
	}
	printf("%d %d %d",max,st[maxi].a,st[maxi].b);
	return 0;
}


