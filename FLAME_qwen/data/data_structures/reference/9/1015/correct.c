#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
struct Line line[2000];
int cmp(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2);


int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].num=1;
	}
	qsort(line,n,sizeof(struct Line),cmp2);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i!=j){
				if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1) {
					line[i].x2=line[j].x2;
					line[i].y2=line[j].y2;
					line[i].num+=line[j].num;
					line[j].x1=0;
					line[j].x2=0;
					line[j].y1=0;
					line[j].y2=0;
					line[j].num=0;
				}		
			}
			
		}
		
	}
	qsort(line,n,sizeof(struct Line),cmp);	
	printf("%d %d %d",line[n-1].num,line[n-1].x1,line[n-1].y1);
	return 0;
}


int cmp(const void*p1,const void*p2)
{
	struct Line *a=(struct Line*)p1;
	struct Line *b=(struct Line*)p2;
	return a->num-b->num;
}

int cmp2(const void*p1,const void*p2)
{
	struct Line *a=(struct Line*)p1;
	struct Line *b=(struct Line*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}

