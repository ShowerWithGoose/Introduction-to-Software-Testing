//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
typedef struct Dian{
	int x,y;
	struct Dian* next;
}dian;
dian tou[105];
int search(int x0,int y0,int n){
	int j;
	for(j=0;j<n;j++){
		if(x0==tou[j].x&&y0==tou[j].y) 
			return j;
	}
	return -1;
}
int main(){
	int n,i,x1,y1,x2,y2;
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		tou[i].x=x1; tou[i].y=y1;
		dian* a=(dian*)malloc(sizeof(dian));
		a->x=x2; a->y=y2;
		tou[i].next=a;
	}
//	for(i=0;i<n;i++) printf("%d %d %d %d\n",tou[i].x,tou[i].y,tou[i].next->x,tou[i].next->y);
	int cnt,xans,yans,loc,ans=0;
	for(i=0;i<n;i++){
		cnt=1;
		x2=tou[i].next->x; y2=tou[i].next->y;
		while(1){
			loc=search(x2,y2,n);
			if(loc==-1) break;
			cnt++;
			x2=tou[loc].next->x; y2=tou[loc].next->y;
		}
		if(cnt>ans){
			ans=cnt;
			xans=tou[i].x;
			yans=tou[i].y;
		}
	}
	for(i=0;i<n;i++) free(tou[i].next);
	
	printf("%d %d %d",ans,xans,yans);
	return 0;
}



