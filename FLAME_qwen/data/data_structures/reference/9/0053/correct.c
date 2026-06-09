#include<stdio.h>
struct line{
	int x1,y1,x2,y2;
	struct line *next;
};
int main(){
	int x,y,n,i,j;
	struct line l[100];
	struct line *p;
	for(i=0;i<100;i++){
		l[i].next=NULL;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
				l[i].next=&l[j];
				break;
			}
		}
	}
	int len,max=0,xe,ye;
	for(i=0;i<n;i++){
		p=&l[i];
		x=l[i].x1;
		y=l[i].y1;
		for(len=1;p->next!=NULL;len++){
			p=(p->next);
		}
		if(max<len){
			max=len;
			xe=x;
			ye=y;
		}
	}
	printf("%d %d %d",max,xe,ye);
}

