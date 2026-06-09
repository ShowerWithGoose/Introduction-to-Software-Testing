#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int x,y;
struct a{
	int x1;
	int y1;
	int x2;
	int y2;
	int m;
}b[105];
int main(int argc,char* argv[]){
	int i,j,n,k,q;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&b[i].x1);
		scanf("%d",&b[i].y1);
		scanf("%d",&b[i].x2);
		scanf("%d",&b[i].y2);
		b[i].m=1;
	}
//	for(i=0;i<n;i++){
//		printf("%d %d %d %d %d\n\n",b[i].x1,b[i].y1,b[i].x2,b[i].y2,b[i].m);
//	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if((b[j].x2==b[k].x1)&&(b[j].y2==b[k].y1)){
					b[j].m+=b[k].m;
					b[j].x2=b[k].x2;
					b[j].y2=b[k].y2;
				//	b[k].x1=0;
				}
			/*	if((b[k].x2==b[j].x1)&&(b[k].y2==b[j].y1)){
					b[k].m+=b[j].m;
					b[k].x2=b[j].x2;
					b[k].y2=b[j].y2;
					b[j].x1=0;
				}*/ 
			}
		}
	}
	for(q=b[0].m,x=b[0].x1,y=b[0].y1,i=1;i<n;i++){
		if(b[i].m>q){
			q=b[i].m;
			x=b[i].x1;
			y=b[i].y1;
		}
	}
	printf("%d %d %d",q,x,y);
//	for(i=0;i<n;i++){
//		printf("%d %d %d %d %d\n",b[i].x1,b[i].y1,b[i].x2,b[i].y2,b[i].m);
//	}
	
}


