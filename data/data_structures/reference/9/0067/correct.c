#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 10005

struct list{
	int x1;
	int x2;
	int y1;
	int y2;
	int count;
}position[N];

int cmp(const void *a,const void *b){
	struct list *c = (struct list*)a;
	struct list *d = (struct list*)b;
	return (c->x1 - d->x1);
}
int cmp1(const void *a,const void *b){
	struct list *c = (struct list*)a;
	struct list *d = (struct list*)b;
	return (c->count - d->count);
}
int main()
{
	int n;
	sc("%d",&n);
	int x1[n],x2[n],y1[n],y2[n];
	for(int i = 0;i < n;i++){
		sc("%d%d%d%d",&position[i].x1,&position[i].y1,&position[i].x2,&position[i].y2);
		position[i].count = 1;
	}
	qsort(position,n,sizeof(position[0]),cmp);
	
	for(int i = 0;i < n;i++){
		if(position[i].count != -1){
			struct list tmp = position[i];
		for(int j = i + 1;j < n;j++){
			if(position[j].count != -1){
				if(tmp.x2 == position[j].x1 && tmp.y2 == position[j].y1){
				position[i].count++;
				position[j].count = -1;
				tmp = position[j];
			}
			}
			
		}
		}
		
	}
	qsort(position,n,sizeof(position[0]),cmp1);
	pf("%d %d %d",position[n - 1].count,position[n - 1].x1,position[n - 1].y1);
	return 0;
}


