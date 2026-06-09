#include<stdio.h>
#include<stdlib.h>
#define N 505
struct poly{
	int x,v;
}a[N],b[N],c[N*N];
int n,m,cnt;
void init(){
	while (1){
		char c; ++n;
		scanf("%d%d%c",&a[n].v,&a[n].x,&c);
		if (c=='\n') break;
	}
	while (1){
		int c;++m;
		scanf("%d%d",&b[m].v,&b[m].x);
		c=getchar();
		if (c==EOF||c=='\n') break;
	}
}
int cmp(const void *A,const void *B){
	struct poly *C=(struct poly *)A;
	struct poly *D=(struct poly *)B; 
	return ((*C).x!=(*D).x)?(*C).x<(*D).x:(*C).v<(*D).v;
} 
void solve(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			c[++cnt].x=a[i].x+b[j].x;
			c[cnt].v=a[i].v*b[j].v;
		}
	qsort(c+1,cnt,sizeof (struct poly ),cmp); int now=1;
	for (int i=2;i<=cnt;i++){
		if (c[now].x==c[i].x) c[now].v+=c[i].v;
			else c[++now]=c[i];
	}
	for (int i=1;i<=now;i++){
		printf("%d %d ",c[i].v,c[i].x);
	}
}
int main(){
	init(); solve();
	return 0;
}

