#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))
#define uint unsigned int
#define uchar unsigned char

struct zuobiao{
	int x1,y1,x2,y2;
	struct zuobiao *next;
}pos[110];
int num[110];

int main(){
	int i,j,n,max=0;
	struct zuobiao *p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&pos[i].x1,&pos[i].y1,&pos[i].x2,&pos[i].y2);
		for(j=0;j<i;j++){
			if((pos[j].x1==pos[i].x2)&&(pos[j].y1==pos[i].y2)){
				pos[i].next=&pos[j];
			}
			if((pos[i].x1==pos[j].x2)&&(pos[i].y1==pos[j].y2)){
				pos[j].next=&pos[i];
			}
		}
	}
	for(i=0;i<n;i++){
		if((p=pos[i].next)!=NULL){
			num[i]+=2;
		}	
		else continue;
		while((p=(*p).next)!=NULL){
			num[i]++;
			if(num[i]>num[max])	max=i;
		}
	}
	printf("%d %d %d",num[max],pos[max].x1,pos[max].y1);
	return 0;
} 

