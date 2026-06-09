#include <stdio.h>

struct point{
	int x[2];
	int y[2];
}point[120],ex;

int main(void) {
	int i,j,k,m=0,n,f,len,xx,yy;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&point[i].x[0],&point[i].y[0],&point[i].x[1],&point[i].y[1]);
	}
	
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n-1;j++){
			if(point[j+1].x[0]<point[j].x[0]){
				ex = point[j];
				point[j] = point[j+1];
				point[j+1] = ex;
				f = 1;
			}
		}
		if(f==0){
			break;
		}
	}
	for(i=0;i<n;i++){
		len = 1;
		k = i;
		for(j=i+1;j<n;j++){
			if(point[k].x[1]==point[j].x[0]&&point[k].y[1]==point[j].y[0]){
				len++;
				k = j;
			}
		}
		if(len>m){
			m = len;
			xx = point[i].x[0];
			yy = point[i].y[0];
		}
	}
	printf("%d %d %d",m,xx,yy);
	return 0;
}

