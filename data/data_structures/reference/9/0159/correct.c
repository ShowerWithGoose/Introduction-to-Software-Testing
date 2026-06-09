#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
} POINT,*PPOINT; 

POINT pt[100]; 
int a[100];


void FIND(PPOINT p1,int n){
	PPOINT p2;
	for(p2=pt;p2<&pt[n];p2++){
		if(p2->x1==p1->x2&&p2->y1==p1->y2)
		p1->flag=(p2-pt);
	} 
}

int CAL(PPOINT p0,int i){
	int n=0;
	PPOINT p1=p0;
	while(p1->flag!=-1){
		n++;
		p1=&pt[p1->flag] ;
	}
	return n;
}

int main(){
	int n,i,max;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		pt[i].flag=-1;
		scanf("%d %d %d %d",&pt[i].x1,&pt[i].y1,&pt[i].x2,&pt[i].y2);
	}
	for(i=0;i<n;i++) 
	FIND(&pt[i],n);
	for(i=0;i<n;i++){
		a[i]=1+CAL(&pt[i],i);
	}
	max=0;
	for(i=1;i<n;i++) 
	max=a[i]>a[max]?i:max;
	printf("%d %d %d",a[max],pt[max].x1,pt[max].y1);
	return 0;
} 

