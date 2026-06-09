#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct _xd{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
} XD; 
int main(){
	XD xd[101];int i=0,n;int max=0,k=0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d %d %d %d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
		xd[i].len=1;i++; 
	}
	for(i=0;i<n;i++){
		int j;
		for( j=i+1;j<n;j++){
			if(xd[j].x2==xd[i].x1&&xd[j].y2==xd[i].y1) {
				xd[j].len+=xd[i].len;xd[j].x2=xd[i].x2;xd[j].y2=xd[i].y2;break;
			}
			if(xd[i].x2==xd[j].x1&&xd[i].y2==xd[j].y1) {
				xd[j].len+=xd[i].len;xd[j].x1=xd[i].x1;xd[j].y1=xd[i].y1;break;
			}
		}
	}
	for(i=0;i<n;i++){
		if(xd[i].len>max) max=xd[i].len,k=i;
	}
	printf("%d %d %d",max,xd[k].x1,xd[k].y1);
	return 0;
}




