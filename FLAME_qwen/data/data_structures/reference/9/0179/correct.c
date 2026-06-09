#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line {
int x1;
int y1;
int x2;
int y2;	
};

int cmp(const void *a,const void *b){
	struct line *one=(struct line *)a;
	struct line *two=(struct line *)b;
	return ((one->x1)-(two->x1));//字符串返回strcmp，此时为从小到大 
}
int main(){
	
struct line p1[110],temp,keep;
int N,i,j,k,count=1,max=0;
scanf("%d",&N);
for(i=0;i<N;i++){
	scanf("%d %d %d %d",&p1[i].x1,&p1[i].y1,&p1[i].x2,&p1[i].y2);
}int flag=0;
qsort(p1,N,sizeof(p1[0]),cmp);


for(i=0;i<N;i++){
	count=1;temp=p1[i];
	for(j=i+1;j<N;j++){
	 if(temp.x2==p1[j].x1&&temp.y2==p1[j].y1){
	 
	 	temp=p1[j];count++;
	 }	
	}
	if(max<count) {
	max=count; 	keep=p1[i];
	}
}

printf("%d",max);printf(" %d %d",keep.x1,keep.y1);
	return 0;
}




