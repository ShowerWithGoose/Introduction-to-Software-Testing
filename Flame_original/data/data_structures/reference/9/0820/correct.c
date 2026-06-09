#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct pos{
	int x;
	int y;
	int x2;
	int y2;
	struct pos *next;
	struct pos *fore;
}po[100]={0,0,0,0,NULL,NULL};
int len[100];
int wz[100];
int main (){
	int n=0,num;
	int i,j;
	int max=0,dwz;
	struct pos *p,*q;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d%d",&po[i].x,&po[i].y);
		scanf("%d%d",&po[i].x2,&po[i].y2);
	}
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			if(po[i].x2==po[j].x&&po[i].y2==po[j].y){
				
				po[i].next=&po[j];
				po[j].fore=&po[i];
			}
		}
	}
	for(i=0;i<num;i++){
		if(po[i].fore==NULL){
			wz[n]=i;//标记起始位置，n为起点数量
			
			struct pos *ptr;
			ptr=&po[i];
			while(ptr->next!=NULL){
				ptr=ptr->next;
				len[n]++;//len为线段段数-1 
			}
			n++; 
			if(max<len[n-1]){
				max=len[n-1];
				dwz=n-1;
			}
		}

	}
	printf("%d %d %d",len[dwz]+1,po[wz[dwz]].x,po[wz[dwz]].y);
	return 0;
} 

