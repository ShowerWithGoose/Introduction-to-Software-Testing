#include<stdio.h>
#include<string.h>

struct line{
	int x1,x2,y1,y2;
}line[100];

int main(){
	int n,i,j,a;
	int flag[300]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int xl[300],yl[300];
	int xr[300],yr[300];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=0;i<n;i++){
		for(a=0;a<n;a++){
		for(j=0;j<n;j++){
			if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2){
				flag[i]++;
				line[i].x1=line[j].x1;
				line[i].y1=line[j].y1;
			}
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
				flag[i]++;
				line[i].x2=line[j].x2;
				line[i].y2=line[j].y2;
			}
		}
	}
	}
	int max=flag[0],biaoji;
	for(i=0;i<n;i++){
		if(flag[i]>max){
			max=flag[i];
			biaoji=i;
		}
	}
	printf("%d %d %d",max,line[biaoji].x1,line[biaoji].y1);
}

