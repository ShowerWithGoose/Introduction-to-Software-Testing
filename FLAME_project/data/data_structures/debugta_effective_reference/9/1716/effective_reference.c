#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lines{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
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
	int i,sum,t,result,flag;
	scanf("%d",&sum);
	for(i=0;i<sum;i++){
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
		list[i].num=0;
	}
	qsort(list,sum,sizeof(list[0]),cmp_y1);
	qsort(list,sum,sizeof(list[0]),cmp_x1);
	for(i=sum-1;i>0;i--){
		for(t=i-1;t>=0;t--){
			if(list[i].x1==list[t].x2&&list[i].y1==list[t].y2)
				list[t].num=list[i].num+1;
			else if(list[i].x2==list[t].x1&&list[i].y2==list[t].y1)
				list[i].num=list[t].num+1;
		}
	}
	for(result=flag=i=0;i<sum;i++){
		if(list[i].num>result){
			result=list[i].num;
			flag=i;
		}
	}
	printf("%d %d %d",result+1,list[flag].x1,list[flag].y1);
	return 0;
}

