#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lines{
	int x1;
	int y1;
	int x2;
	int y2;
	int next;
}line;

int cmp_x1(const void*a,const void*b){
	line *m=(line *)a;
	line *n=(line *)b;
	return m->x1-n->x1;
}

int cmp_y1(const void*a,const void*b){
	line *m=(line *)a;
	line *n=(line *)b;
	return m->y1-n->y1;
}

int main() {
	line list[100];
	int i,num,t,count,flag;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
		list[i].next=0;
	}
	qsort(list,num,sizeof(list[0]),cmp_y1);
	qsort(list,num,sizeof(list[0]),cmp_x1);
	for(i=num-1;i>0;i--){
		for(t=i-1;t>=0;t--){
			if(list[i].x1==list[t].x2&&list[i].y1==list[t].y2)
				list[t].next=list[i].next+1;
			else if(list[i].x2==list[t].x1&&list[i].y2==list[t].y1)
				list[i].next=list[t].next+1;
		}
	}
	for(count=flag=i=0;i<num;i++){
		if(list[i].next>count){
			count=list[i].next;
			flag=i;
		}
	}
	printf("%d %d %d",count+1,list[flag].x1,list[flag].y1);
	return 0;
}

