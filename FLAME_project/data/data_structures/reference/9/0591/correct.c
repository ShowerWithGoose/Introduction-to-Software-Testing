#include<stdio.h>
int n,i,p,p0,cnt=0;
long long a[102],b[102],c[102],d[102];
int flag[102]= {0},m=1;
long long aa,bb;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
	}
	for(p=1; p<=n; p++) {
		m=1;
		p0=p;
		for(i=1; i<=n; i++) {
			if(i!=p) {
				if(a[i]==c[p]&&b[i]==d[p]) {
					m++;
					flag[i]++;
					p=i;
					i=0;
				}
			}
		}
		if(m>cnt) {
			cnt=m;
			m=1;
			aa=a[p0];
			bb=b[p0];
		}
		p=p0;
	}
	printf("%d %lld %lld\n",cnt,aa,bb);
	return 0;
}

