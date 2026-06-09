#include<stdio.h>
#include<string.h>
int N,i;
int qx,qy,tx,ty;
int len,max;
int qx,qy,tx,ty,j;
struct numxy{
	int x1,y1,x2,y2,judge;
}list[1005];
void seek(int i){
	 list[i].judge++;
	 qx=list[i].x1,qy=list[i].y1,tx=list[i].x2,ty=list[i].y2;
	 for(j=0;j<N;j++){
	 	 if(list[j].judge!=0)continue;
		 if(list[j].x2==qx&&list[j].y2==qy){
	 		qx=list[j].x1;
	 		qy=list[j].y1;
	 		len++;
	 		list[j].judge++;
			j=0;
	 	}
	 }
	 for(j=0;j<N;j++){
	 	if(list[j].judge!=0)continue;
		 if(list[j].x1==tx&&list[j].y1==ty){
	 		tx=list[j].x2;
	 		ty=list[j].y2;
	 		len++;
	 		list[j].judge++;
			j=0;
	 	}
	 }
	 for(j=0;j<N;j++){
	 	list[j].judge=0;
	 }
}
int main(){
	int xa,xb,ya,yb;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	}
	len=1;
	for(i=0;i<N;i++){
		seek(i);
		if(len>max){
			max=len;
			xa=qx;ya=qy;xb=tx;yb=ty;
		}
		len=1;
	}
    printf("%d ",max);
	xa<xb?printf("%d %d",xa,ya):printf("%d %d",xb,yb);
	return 0;
} 



