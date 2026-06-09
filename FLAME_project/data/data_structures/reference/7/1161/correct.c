#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
struct node {
	int num,deep,last;
	int le,ri;
} a[200000];
int n,i,t,p,l;
void find(int po) {
	if(a[po].last==0) {
		printf("%d %d\n",a[po].num,a[po].deep);
		return ;
	}
	if(a[po].le)
		find(a[po].le);
	if(a[po].ri)
		find(a[po].ri);
}
int main() {
	scanf("%d",&n);
	scanf("%d",&t);
	l++;
	a[l].num=t,a[l].deep=1;
	for(i=1; i<=n-1; i++) {
		scanf("%d",&t);
		p=1;
		l++,a[l].num=t;
		while(1) {
			if(t>=a[p].num&&a[p].ri)
				p=a[p].ri;
			else if(t<a[p].num&&a[p].le)
				p=a[p].le;
			else break;
		}
		a[l].deep=a[p].deep+1;
		a[p].last=1;
		if(t>=a[p].num) {
			a[p].ri=l;
		}
		if(t<a[p].num) {
			a[p].le=l;
		}
	}
	find(1);
	return 0;
}



