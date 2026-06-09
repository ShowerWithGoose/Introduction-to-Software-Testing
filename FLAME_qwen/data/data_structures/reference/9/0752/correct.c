#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct LOCATION{
	int x;
	int y;
}loc;
typedef struct UNIT{
	loc start;
	loc end;
	int num;
}unit;
int cmp(const void *a,const void *b){
	int *x=(int*)a;
	int *y=(int*)b;
	return x[0]-y[0];
}
unit p[120];
int arrayEnd=0;
int main() {
	int n;
	scanf("%d",&n);
	int data[n][4];
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
	}
	qsort(data,n,4*sizeof(int),cmp);
	loc tempStart,tempEnd;
	int flag;
	for(int i=0;i<n;i++){
		tempStart.x=data[i][0];
		tempStart.y=data[i][1];
		tempEnd.x=data[i][2];
		tempEnd.y=data[i][3];
		flag=0;
		for(int j=0;j<arrayEnd;j++){
			if(tempStart.x==p[j].end.x&&tempStart.y==p[j].end.y){
				p[j].num++;
				p[j].end=tempEnd;
				flag=1;
				break;
			}
			if(tempEnd.x==p[j].start.x&&tempEnd.y==p[j].start.y){
				p[j].num++;
				p[j].start=tempStart;
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		p[arrayEnd].start=tempStart;
		p[arrayEnd].end=tempEnd;
		p[arrayEnd].num=1;
		arrayEnd++;
	}
	int max=0;
	int maxi;
	for(int i=0;i<arrayEnd;i++){
//		printf("%d %d %d %d\n",i,p[i].num,p[i].start.x,p[i].start.y);
		if(max<p[i].num){
			maxi=i;
			max=p[i].num;
		}
	}
	printf("%d %d %d\n",p[maxi].num,p[maxi].start.x,p[maxi].start.y);
    return 0;
}












