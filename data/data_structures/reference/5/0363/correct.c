#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_N 9000010
#define ll long long

int n,m,q;
struct Node{
	ll val;//系数 
	ll num;//指数 
}p[MAX_N];
ll a1[MAX_N],b1[MAX_N];
ll a2[MAX_N],b2[MAX_N];
void calc() {
	int i,j,k;
	q=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			int flag=0;
			for(k=1;k<=q;k++) {
				if(p[k].num==b1[i]+b2[j]) {
					flag=1;
					p[k].val+=1ll*a1[i]*a2[j];
					break;
				}
			}
			if(!flag) {
				p[++q].val=1ll*a1[i]*a2[j];
				p[q].num=b1[i]+b2[j];
			}
		}
	}
}
int cmp(const void * x,const void * y) {
	struct Node * a=(struct Node *)x;
	struct Node * b=(struct Node *)y;
	if((a->num)<(b->num)) return 1;
	return -1;
}
int main() {
//	ll tmp=2000000000000000000ll;
	ll x,y;
	char s;
	while(1) {
		++n;
		scanf("%lld%lld",&a1[n],&b1[n]);
		scanf("%c",&s);
		if(s=='\n') break;
	}
	while(1) {
		++m;
		scanf("%lld%lld",&a2[m],&b2[m]);
		scanf("%c",&s);
		if(s=='\n') break;
	}
//	while(scanf("%lld%lld",&x,&y)!=EOF) {
//		if(tmp<y) {
//			++m;
//			a2[m]=x;b2[m]=y;
//			break;
//		}
//		++n;
//		a1[n]=x;b1[n]=y;
//		tmp=y;
//	}
//	int i;
//	while(scanf("%lld%lld",&x,&y)!=EOF) {
//		++m;
//		a2[m]=x;b2[m]=y;
//	}
//	printf("%d",n);
//	for(i=1;i<=m;i++) printf("%lld %lld\n",a2[i],b2[i]);
	calc();
	qsort(p+1,q,sizeof(p[1]),cmp);
//	puts("1");
	int i;
	for(i=1;i<=q;i++) {
		if(p[i].val==0) continue;
		printf("%lld %lld ",p[i].val,p[i].num);
	}
	return 0;
}

