#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
struct node{
	int x1,x2,y1,y2;
}a[1010];
int n;
struct edge{
	int v,next;
}e[20010];
int head[1010],size,vis[1010];
int cmp(const void *a,const void *b){
	return (*(struct node *)a).x1>(*(struct node*)b).x1;
}
void insert(int u,int v){
	e[++size].v=v;
	e[size].next=head[u];
	head[u]=size;
	return;
}
int main(){
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		scanf ("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
//	qsort(a+1,n,sizeof (a[1]),cmp);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (a[i].x2==a[j].x1&&a[i].y2==a[j].y1){
				vis[i]=j;
			}
		}
	}
	int ans=1,maxi=1;
	for (int i=1;i<=n;i++){
		int p=i;
		int tmp=1;
		while (vis[p]!=0){
			p=vis[p];
			tmp++;
		}
		if (tmp>ans){
			maxi=i;
			ans =tmp;
		}
	}
	printf("%d %d %d",ans,a[maxi].x1,a[maxi].y1);
	return 0;
}

