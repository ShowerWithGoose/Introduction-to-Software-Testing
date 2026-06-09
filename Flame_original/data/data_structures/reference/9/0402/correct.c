#include <stdio.h>
#include <stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int number;
}all_line[10000];
int cmp_x1(const void *a,const void *b){
	struct line *aa=(struct line *)a;
	struct line *bb=(struct line *)b;
	return aa->x1-bb->x1;
}
int cmp_number(const void *a,const void *b){
	struct line *aa=(struct line *)a;
	struct line *bb=(struct line *)b;
	return aa->number-bb->number;
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++) scanf("%d%d%d%d",&all_line[i].x1,&all_line[i].y1,&all_line[i].x2,&all_line[i].y2);
	qsort(all_line,n,sizeof(all_line[0]),cmp_x1);
	for(i=0;i<n;i++) all_line[i].number=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(all_line[i].x2==all_line[j].x1&&all_line[i].y2==all_line[j].y1){
				all_line[i].x2=all_line[j].x2;
				all_line[i].y2=all_line[j].y2;
				all_line[i].number++;
			}
		}
	}
	qsort(all_line,n,sizeof(all_line[0]),cmp_number);
	printf("%d %d %d",all_line[n-1].number,all_line[n-1].x1,all_line[n-1].y1);
	return 0;
}



