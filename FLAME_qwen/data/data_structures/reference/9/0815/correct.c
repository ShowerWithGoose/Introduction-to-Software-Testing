#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
struct linc{
	int x0,y0,y1,x1,count; 
	struct linc *link;
}l[500],tmp;
int main(){
	int len,max=0,j,i,n,x,y;
	struct linc *a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		l->link=NULL;//全部指向空 
		scanf("%d%d%d%d",&l[i].x0,&l[i].y0,&l[i].x1,&l[i].y1);
		l[i].count=0;
	}
	for(i=0;i<n;i++)//根据起点，排序 
		for(j=i+1;j<n;j++)
			if(l[i].x0>l[j].x0||(l[i].x0==l[j].x0&&l[i].y0>l[j].y0)){
				tmp=l[i];
				l[i]=l[j];
				l[j]=tmp;
			}				
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(l[i].x1==l[j].x0&&l[i].y1==l[j].y0){
				l[i].link=&l[j];
			}
	for(i=0;i<n;i++){
		a=&l[i];
		while(a!=NULL){//有下一连接点
			l[i].count++; 
			a=a->link;
		}
	}
	for(i=0;i<n;i++){
		if(l[i].count>max){
			max=l[i].count;
			x=l[i].x0;
			y=l[i].y0;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
} 

