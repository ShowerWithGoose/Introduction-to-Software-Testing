#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int x1;
	int x2;
	int y1;
	int y2;
	int flag;
	int cnt;
}line;
int cmp(const void *a, const void *b){
    line c = *(line *)a;
    line d = *(line *)b;
    if(c.x1>d.x1)return 1;
    return -1;
}
line l[10000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,n,sizeof(l[0]),cmp);
	for(int i=0;i<n;i++){
		if(l[i].flag)continue;
		for(int j=i+1;j<n;j++){
			if(l[j].flag)continue;
			if(l[j].x1==l[i].x2&&l[j].y1==l[i].y2){
				l[i].x2=l[j].x2;
				l[i].y2=l[j].y2;
				l[j].flag=1;
				l[i].cnt++;
			}
		}
	}
	int max=0;
	for(int i=0;i<n;i++)if(l[i].cnt>max)max=l[i].cnt;
	for(int i=0;i<n;i++)if(l[i].cnt==max)printf("%d %d %d",l[i].cnt+1,l[i].x1,l[i].y1);
	return 0;
}

