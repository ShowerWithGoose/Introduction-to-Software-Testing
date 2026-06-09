#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int length;
}LINE;
LINE line[105];
int a[105];
int n;
int rise(const void *a,const void *b){
	LINE *p = (LINE *)a;
	LINE *q = (LINE *)b;
	if(p->x1 > q->x1) return 1;
	else if(p->x1 < q->x1) return -1;
	return 0;
}
int dfs(int m){
	for(int i=m+1; i<=n; i++){
		if(line[i].x1==line[m].x2&&line[i].y1==line[m].y2){
			return dfs(i)+1;
		}
	}return 1;
}
int main(){	
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}qsort(line+1,n,sizeof(LINE),rise);
	for(int i=1; i<=n; i++){
		a[i]=dfs(i);
	}int max=-1,point=0;
	for(int i=1; i<=n; i++){
		if(a[i]>max){
			max=a[i];
			point=i;
		}
	}
	printf("%d %d %d",max,line[point].x1,line[point].y1);
	return 0;
}

