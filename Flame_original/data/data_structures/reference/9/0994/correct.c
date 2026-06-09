#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define mian main
#define MAX_N 105

typedef struct LINE{
	
	int x1;
	int y1;
	int x2;
	int y2;
	
}line;

int cnt[MAX_N];

int Comp(const void *_p1,const void * _p2);

void LineToLine(line date[],int);

int main(){
	
	int n;
	for(int i=0;i<MAX_N;i++)
		cnt[i]=1;
	scanf("%d",&n);
	line date[n+1];
	for(int i=0;i<n;i++)
		scanf("%d %d %d %d",&date[i].x1,&date[i].y1,&date[i].x2,&date[i].y2);
	qsort(date,n,sizeof(line),Comp);
//	LineToLine(date,n);
	for(int i=n-1;i>0;i--){
		for(int j=i-1;j>=0;j--){
			if((date[i].x1==date[j].x2)&&(date[i].y1==date[j].y2)){
				cnt[j]+=cnt[i];
			}
		}
	}
	int MaxNum=1,MaxPoint=0;
	for(int i=0;i<n;i++){
		if(MaxNum<cnt[i]){
			MaxNum=cnt[i];
			MaxPoint=i;
		}
	}
	printf("%d %d %d\n",MaxNum,date[MaxPoint].x1,date[MaxPoint].y1);
	
	return 0;
}

int Comp(const void *_p1,const void * _p2){
	
	line *p1=(line *)_p1;
	line *p2=(line *)_p2;
	return p1->x1-p2->x1;

}

void LineToLine(line date[],int n){
	
	for(int i=n-1;i>0;--i){
		for(int j=i-1;j>=0;--j){
			if((date[i].x1==date[j].x2)&&(date[i].y1==date[j].y2)){
				cnt[j]+=cnt[i];
			}
		}
	}
	
	return ;
}

