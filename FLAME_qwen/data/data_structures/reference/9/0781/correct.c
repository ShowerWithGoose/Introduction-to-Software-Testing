#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Line{
	int qua;
	int startx,starty;
	int endx,endy;
}line[150],temp;
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].startx,&line[i].starty,&line[i].endx,&line[i].endy);
		line[i].qua=1;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(line[i].startx>line[j].startx){
				temp=line[i];line[i]=line[j];line[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(line[j].startx==line[i].endx&&line[j].starty==line[i].endy){
				line[i].qua++;
				line[i].endx=line[j].endx;
				line[i].endy=line[j].endy;
				line[j].startx=-1;
			}
		}
	}
	int count=0,x=0,y=0;
	for(i=0;i<n;i++){
		if(line[i].qua>count){
			count=line[i].qua;
			x=line[i].startx;
			y=line[i].starty;
		}
	}
	printf("%d %d %d",count,x,y);
}

