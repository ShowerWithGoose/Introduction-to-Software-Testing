#include <stdio.h>
typedef struct{
	int x1,x2,y1,y2,num;
}Line;
int cmp(const void *p1, const void *p2){
	Line *q1=(Line*)p1;
	Line *q2=(Line*)p2;
	if(q1->x1!=q2->x1){
		return q1->x1-q2->x1;
	}else{
		return q1->y1-q2->y1;
	}
}

int main()
{
	Line l[200];
	int x;//Ïß¶ÎÊýÁ¿ 
	int i,j;
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].num=1;
	}
	qsort(l,x,sizeof(Line),cmp);
	
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			if(i==j)	continue;
			else{
				if(l[i].x2==l[j].x1 && l[i].y2==l[j].y1){
					l[i].x2=l[j].x2;
					l[i].y2=l[j].y2;
					l[i].num+=l[j].num;
					l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].num=0;
				}
			}
		}
	}
	int max=0,a,b;
	for(i=0;i<x;i++){
		if(l[i].num>max){
			max=l[i].num;
			a=l[i].x1;
			b=l[i].y1;
		}
	}
	printf("%d %d %d",max,a,b);
	return 0;
} 

