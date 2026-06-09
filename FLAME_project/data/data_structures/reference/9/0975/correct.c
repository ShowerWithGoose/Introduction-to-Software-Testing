#include <stdio.h>
#include <stdlib.h>

struct L{
	int x1;
	int y1;
	int x2;
	int y2;
}Line[105];

int cmp(const void *a,const void *b);

int main(){
	int N,i,j,CurrentLength=0,MaxLength=0,HeadPosition=0,flag;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&Line[i].x1,&Line[i].y1,&Line[i].x2,&Line[i].y2);
	}
	qsort(Line,N,sizeof(struct L),cmp);
	for(i=0;i<N;i++){
		CurrentLength=1;
		flag=i;
		j=1;
		while(j<N){
			while((j<N)&&((Line[i].x2!=Line[j].x1)||(Line[i].y2!=Line[j].y1))){
				j++;
			}
			if(j<N){
				CurrentLength++;
				i=j;
				j=i+1;
			}
		}
		HeadPosition=(CurrentLength>MaxLength)?flag:HeadPosition;
		MaxLength=(CurrentLength>MaxLength)?CurrentLength:MaxLength;
		i=flag;
	}
	printf("%d %d %d\n",MaxLength,Line[HeadPosition].x1,Line[HeadPosition].y1);
	return 0;
}

int cmp(const void *a,const void *b){
	struct L *c=(struct L *)a;
	struct L *d=(struct L *)b;
	if(c->x1!=d->x1){
		return (c->x1<d->x1)?-1:1;
	}
	else{
		return (c->y1<d->y1)?-1:1;
	}
}

