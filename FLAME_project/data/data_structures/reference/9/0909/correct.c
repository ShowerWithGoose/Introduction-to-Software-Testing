#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct loc{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}loc;
loc arr[150];
int compare(loc *a,loc *b){
	return a->x1 - b->x1 ;
}
int main(){
	int n;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&arr[i].x1 ,&arr[i].y1 ,&arr[i].x2 ,&arr[i].y2 );
		arr[i].num = 1;
	}
	qsort(arr,n,sizeof(loc),compare);
	int a;
	for(i=0;i<n-1;i++){
		if(arr[i].num ==0){
			continue;
		}
		for(j=i+1,a=i;j<n;j++){
			if(arr[j].x1 ==arr[a].x2 &&arr[j].y1 ==arr[a].y2 ){
				arr[i].num ++;
				arr[j].num =0;
				a = j;
			}
		}
	}
	int max=0,p=0;
	for(k=0;k<n;k++){
		if(arr[k].num >max){
			max = arr[k].num ;
			p = k;
		}
	}
	printf("%d %d %d",max,arr[p].x1 ,arr[p].y1 );
	return 0;
}

