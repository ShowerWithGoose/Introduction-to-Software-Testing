#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct points{
	int startx;
	int starty;
	int endx;
	int endy;
	int num;
}point;
int cmp(const void*p1,const void*p2){
	point *a=(point*)p1;
	point *b=(point*)p2;
	int ans;
	if(a->startx>b->startx)return -1;
	else if(a->startx<b->startx)return 1;
	else return b->starty-a->starty;
}

int main(){
	int i,j,k;
	point line[105];
	int n;
	int num;
	int ans[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].startx,&line[i].starty,&line[i].endx,&line[i].endy);
	}
	qsort(line,n,sizeof(point),cmp);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(line[i].startx==line[j].endx&&line[i].starty==line[j].endy){
				line[j].num=line[i].num+1;
			}
		}
	}		
	int max=0,cnt=0;
	for(i=0;i<n;i++){
		if(line[i].num>max){
		max=line[i].num;cnt=i;}
		else max=max;
	}
    printf("%d %d %d",max+1,line[cnt].startx,line[cnt].starty);
    return 0;
}

