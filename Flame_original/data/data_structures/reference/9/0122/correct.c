#include<stdio.h>
#include<string.h>
 struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;
};
typedef struct line L;
int cmp(const void*p1 ,const void*p2){
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	if(a->x1!=b->x1)
	return a->x1-b->x1;
	else return a->y1-b->y1;
}
int cmp2(const void*p1 ,const void*p2){
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	return a->cnt-b->cnt;
}
int main(){
    L l[105];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		l[i].cnt=1;}
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,n,sizeof(L),cmp);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		
				if(i!=j&&l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
				l[i].cnt+=l[j].cnt;
				l[i].x2=l[j].x2;
				l[i].y2=l[j].y2;
				l[j].x1=0,l[j].y2=0,l[j].x2=0,l[j].y1=0,l[j].cnt=0;
			}
				
		}
	}
	qsort(l,n,sizeof(L),cmp2);
	printf("%d %d %d",l[n-1].cnt,l[n-1].x1,l[n-1].y1);
	
} 

