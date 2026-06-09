#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct line{
	int x1,x2,y1,y2;
};
int cmp(const void* a1,const void *a2);
int main(){
	int num,i,j,cnt=0,len_max=0,x1_max,y1_max,xtemp,ytemp;
	struct line a[1005];
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,num,sizeof(struct line),cmp);
	for(i=0;i<num-1;i++){
		cnt=0;
		xtemp=a[i].x2;ytemp=a[i].y2;
		for(j=i+1;j<num;j++){
			if(a[j].x1==xtemp&&a[j].y1==ytemp){
				cnt++;
				xtemp=a[j].x2;ytemp=a[j].y2;
			}
		}
		if(cnt>len_max){
			len_max=cnt;
			x1_max=a[i].x1;y1_max=a[i].y1;
		}
	} 
	printf("%d %d %d",len_max+1,x1_max,y1_max);

	return 0;
}

int cmp(const void* a1,const void *a2){
	struct line *b1=(struct line *)a1,*b2=(struct line*)a2;
	if(b1->x1>b2->x1) return 1;
	else return -1;
}

