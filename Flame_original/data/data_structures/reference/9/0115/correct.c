#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a, const void *b);
struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
}line[101];
int tmpx1,tmpy1;
int flag[101];
int cnt=0;
int next[101];
int maxx1,maxy1,maxcnt;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	//首尾相连的坐标满足x2[p]==x1[q]&&y2[p]==y1[q]
	qsort(line, n, sizeof(line[0]), cmp);
	//按照各个线段左侧点的横坐标从小到大排序
//	for(int i=0;i<n;i++){
//		printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
//	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
				next[i]=j;
			}
		}
	}
	for(int i=0;i<n;i++){
		cnt=1;
		tmpx1=line[i].x1;
		tmpy1=line[i].y1;
		while(next[i]!=0){
			i=next[i];
			cnt++;
		}
		if(cnt>maxcnt){
			maxcnt=cnt;
			maxx1=tmpx1;
			maxy1=tmpy1;
		}
	}
	printf("%d %d %d",maxcnt,maxx1,maxy1);
	return 0;
}
int cmp(const void *a, const void *b)
{
    if((*(struct Line*)a).x1<=(*(struct Line*)b).x1)
	return -1;
	else
	return 1;
}

