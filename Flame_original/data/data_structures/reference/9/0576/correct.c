#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct point{
	int x[3];
	int y[3];
	int cnt;
}line[105];

int main (){
	int i,n,j,maxlen=0,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x[0],&line[i].y[0],&line[i].x[1],&line[i].y[1]);
		line[i].cnt =1;
	}
	
	for(i=0;i<n;i++){
		if(!line[i].cnt ) continue;
		for(j=0;j<n;j++){
			if((line[i].x[1]==line[j].x[0])&&(line[i].y[1]==line[j].y[0])&&(line[j].cnt!=0)){
				line[i].x[1]=line[j].x[1];
				line[i].y[1]=line[j].y[1];
				line[i].cnt+=line[j].cnt;
				line[j].cnt=0;
			}
			else if((line[i].x[0]==line[j].x[1])&&(line[i].y[0]==line[j].y[1])&&(line[j].cnt!=0)){
					line[i].x[0]=line[j].x[0];
					line[i].y[0]=line[j].y[0];
					line[i].cnt+=line[j].cnt;
					line[j].cnt=0;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(line[i].cnt>maxlen){
			maxlen=line[i].cnt;
			k=i;
		}		
	}
	printf("%d %d %d",maxlen,line[k].x[0],line[k].y [0]);
}
