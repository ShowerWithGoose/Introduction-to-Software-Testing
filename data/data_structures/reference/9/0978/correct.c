#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct info{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
int main (){
	int n,i,j,k=0,shline[100][5],flag=0,longest,max;
	struct info line[105];
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&shline[i][0],&shline[i][1],&shline[i][2],&shline[i][3]);
	    if(i!=n-1)scanf("\n");
	}
	for(i=0,k=0;i<n;i++){
		flag=0;
		for(j=0;j<n;j++){
			if(i==j)continue;
			if(shline[i][0]==shline[j][2]&&shline[i][1]==shline[j][3]){
				flag=1;//i不是起点 
				break;				
			}
		}
		if(flag==0){//定起点，对所有首点不等的点 
			line[k].x1=shline[i][0];
			line[k].y1=shline[i][1];
			line[k].x2=shline[i][2];
			line[k].y2=shline[i][3];
			line[k++].num=1;
		}
	}
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			if(line[i].x2==shline[j][0]&&line[i].y2==shline[j][1]){//i的尾能接上j 数组 
				line[i].num++;
				line[i].x2=shline[j][2];
				line[i].y2=shline[j][3];//更改i的尾 
				j=-1;//尾点变化，shline从头开始判断 
			}
	    }
    }
    for(i=0,longest=line[0].num,max=0;i<k;i++){
    	if(line[i].num>longest){
    		longest=line[i].num;
    		max=i;
		}
	}
	printf("%d %d %d",longest,line[max].x1,line[max].y1);
	return 0;
}
/*10
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120*/

