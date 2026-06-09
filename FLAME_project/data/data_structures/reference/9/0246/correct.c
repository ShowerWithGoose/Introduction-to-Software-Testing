#include<stdio.h>
#define N 105 
int n;
struct node{
	int x1,x2,y1,y2;
}a[N];
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
}
int pre[N],flag[N],xx,yy,mx;
void solve(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i].x1==a[j].x2&&a[i].y1==a[j].y2){
				pre[i]=j; flag[j]=1; break;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (!flag[i]){
			int cnt=0,j=i,x,y;
			x=a[i].x1,y=a[i].y1;
			while (j){
				x=a[j].x1,y=a[j].y1;
				j=pre[j]; cnt++;
			}
			if (cnt>mx) mx=cnt,xx=x,yy=y;
		}
	}
	printf("%d %d %d\n",mx,xx,yy);
}
int main(){
	init(); solve();
	return 0;	
}

