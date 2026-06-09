#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

/*
THINK:
首先，需要储存数据，
其次，进行排列（从小到大），
而后进行线段的连接，
同时记录线段的起始点以及终末点的坐标，
同时记录组成的线段数，
KEY：
连接
WAY:

*/

int main(){
	struct LINESTORE{
		int x1;
		int y1;
		int x2;
		int y2;
	}line[MAXSIZE],p;
	struct Store{
		int n;
		int start;
		int finish;	
		int start0;
		int finish0;	
	}store[MAXSIZE];
	int N,X,Y;
	int Number,i=0;
	scanf("%d",&Number);
	while(i<Number){
		scanf("%d",&line[i].x1);	
		scanf("%d",&line[i].y1);
		scanf("%d",&line[i].x2);
		scanf("%d",&line[i].y2);
		i++;
	}
	
	printf("\n");
	i=0;
	for(int i=0;i<Number;i++){
		for(int j=0;j<Number-1;j++){
			if(line[j].x1>line[1+j].x1){
				p=line[j];
				line[j]=line[j+1];
				line[j+1]=p;
			}			
		}
	}
	

    
	for(int i=0;i<Number;i++){
		
		store[i].n=1;
		store[i].start=line[i].x1;
		store[i].finish=line[i].y1;
		store[i].start0=line[i].x2;
		store[i].finish0=line[i].y2;
				
		for(int j=i+1;j<Number;j++){
			if((store[i].start0==line[j].x1)&&(store[i].finish0==line[j].y1)){
				store[i].n=store[i].n+1;
				store[i].start0=line[j].x2;
				store[i].finish0=line[j].y2;
			}
		}
	}
	N=store[0].n;
	X=store[0].start;
	Y=store[0].finish;
	for(int i=0;i<Number;i++){
		if(N<store[i].n){
			N=store[i].n;
			X=store[i].start;
			Y=store[i].finish;
		}
	}
	printf("%d %d %d",N,X,Y);
	
	
	return 0;
} 

