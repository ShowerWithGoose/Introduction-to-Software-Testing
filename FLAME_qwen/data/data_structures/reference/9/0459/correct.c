#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct xianduan {
		int x1,x2,y1,y2;
	}xd[200];
int ss(int i1,int N){
	for(int i=1;i<=N;i++){
		if(xd[i].x1==xd[i1].x2&&xd[i].y1==xd[i1].y2){
			return ss(i,N)+1;
		}
	}
	return 1;
}
int main(){	
	int N,maxl=0,maxx,k,maxy;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d%d%d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
	}
	for(int i=1;i<=N;i++){
		k=ss(i,N);
		if(maxl<k){
			maxl=k;
			maxx=xd[i].x1;
			maxy=xd[i].y1;
		}
	}
	printf("%d %d %d",maxl,maxx,maxy);
	return 0;
}
