#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int x0[103]={},y0[103]={};
int x1[103]={},y1[103]={};
int numb;
int times=0,mnum;
void findNext(int n){
	int m=n;
	n=numb;
	times++;
	while(n--){
		if(n==m) continue;
		if(x1[m]==x0[n] && y1[m]==y0[n]){
			if(x0[n]<x0[mnum]) mnum=n;
			findNext(n);
		}
		/*
		if(x0[m]==x0[n] && y0[m]==y0[n]){
			if(x0[n]<x0[mnum]) mnum=n;
			findNext(n);
		}
		if(x1[m]==x1[n] && y1[m]==y1[n]){
			if(x0[n]<x0[mnum]) mnum=n;
			findNext(n);			
		}
		if(x1[m]==x0[n] && y1[m]==y0[n]){
			if(x0[n]<x0[mnum]) mnum=n;
			findNext(n);			
		}*/	
	}
	return;
}

int main(){
	int n,maxNum=0,maxTimes=0,num;
	scanf("%d",&n);
	numb=n;
	while(n--)
		scanf("%d%d%d%d",&x0[n],&y0[n],&x1[n],&y1[n]);
	num=numb;
	while(num--){
		times=0;mnum=num;
		findNext(num);//找到最多段的线段
		if(maxTimes<times){//无需考虑两个最长线段
			maxTimes=times;
			maxNum=mnum;
		}
	}
	printf("%d %d %d\n",maxTimes,x0[maxNum],y0[maxNum]);
	
	
	
	return 0;
}

