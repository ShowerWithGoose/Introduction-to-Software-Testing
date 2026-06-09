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
int i,j,n=0;
scanf("%d",&n);
for(i=0;i<n;i++)line[i].len=1;
for(i=0;i<n;i++){
	scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);

}
qsort(line,n,sizeof(Line),cmp);
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
			line[i].x2=line[j].x2,line[i].y2=line[j].y2;
			line[i].len+=line[j].len;
			line[j].x1=line[j].x2=line[j].y1=line[j].y2=line[j].len=0;
		}
	}
}
int max=1,tmp=0;
for(int i=0;i<n;i++){
	if(max<line[i].len) max=line[i].len,tmp=i;

}
printf("%d %d %d",max,line[tmp].x1,line[tmp].y1);


return 0;
}
int cmp(const void *p,const void *q){
	struct LINE *a=(struct LINE*)p;
	struct LINE *b=(struct LINE*)q;
	if(a->x1!=b->x1){
		return a->x1-b->x1;
	}else return a->y1-b->y1;
	
	
	
}

