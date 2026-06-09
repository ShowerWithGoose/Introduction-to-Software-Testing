#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int cmp(const void *p1,const void *p2){
	int *a=(int *)p1;int *b=(int *)p2;
	if(a[0]>b[0])return 1;
	else if(a[0]<b[0])return -1;
	else {
		if(a[1]>b[1])return 1;
		else return -1;
	} 
}
int main(){
	int n;
	int point[105][5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]);
	}
	qsort(point[1],n,sizeof(point[0]),cmp);
//	for(int i=1;i<=n;i++){ 
//		for(int j=0;j<=3;j++)printf("%d ",point[i][j]);
//		printf("\n");
//	} 
	int max=0,tem,resx,resy;
	for(int i=1;i<=n;i++){
		int now=i;tem=1;
		for(int j=1;j<=n;j++){
			if(point[now][2]==point[j][0]&&point[now][3]==point[j][1]){
				now=j;tem++;	//now是目前为止以第i个point为起点的线段 的终点线段 
			}
		}
		if(tem>max){
			max=tem;
			resx=point[i][0],resy=point[i][1];
		}
	}
	printf("%d %d %d",max,resx,resy);
	return 0;
}


