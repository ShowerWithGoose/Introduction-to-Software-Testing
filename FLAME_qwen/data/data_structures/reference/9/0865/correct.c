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
	int n,i,j,num=0,maxnum=0,bx,by,x,y;
	struct line a[1005];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(struct line),cmp);
	for(i=0;i<n-1;i++){
		num=0;
		x=a[i].x2;y=a[i].y2;
		for(j=i+1;j<n;j++){
			if(a[j].x1==x&&a[j].y1==y){
				num++;
				x=a[j].x2;y=a[j].y2;
			}
		}
		if(num>maxnum){
			maxnum=num;
			bx=a[i].x1;by=a[i].y1;
		}
	} 
	printf("%d %d %d",maxnum+1,bx,by);

	return 0;
}

int cmp(const void* a1,const void *a2){
	struct line *b1=(struct line *)a1,*b2=(struct line*)a2;
	if(b1->x1>b2->x1) return 1;
	else return -1;
}

