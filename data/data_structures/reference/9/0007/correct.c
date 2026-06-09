#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
int cmp(const void *p,const void *q);
struct LINE{
	int x1,x2,y1,y2;
	int len;
};
typedef struct LINE Line;
Line line[200];
int main(){ 
int i,j,cnt=0;
scanf("%d",&cnt);
for(i=0;i<cnt;i++)line[i].len=1;
for(i=0;i<cnt;i++){
	scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);

}
qsort(line,cnt,sizeof(Line),cmp);
for(i=0;i<cnt;i++){
	for(j=i+1;j<cnt;j++){
		if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
			line[i].x2=line[j].x2,line[i].y2=line[j].y2;
			line[i].len+=line[j].len;
			line[j].x1=line[j].x2=line[j].y1=line[j].y2=line[j].len=0;
		}
	}
}
int max=1,location=0;
for(int i=0;i<cnt;i++){
	if(max<line[i].len) max=line[i].len,location=i;

}
printf("%d %d %d",max,line[location].x1,line[location].y1);


return 0;
}
int cmp(const void *p,const void *q){
	struct LINE *a=(struct LINE*)p;
	struct LINE *b=(struct LINE*)q;
	if(a->x1!=b->x1){
		return a->x1-b->x1;
	}else return a->y1-b->y1;
	
	
	
}

