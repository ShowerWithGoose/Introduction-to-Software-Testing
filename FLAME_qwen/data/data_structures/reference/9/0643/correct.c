#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct line{
	int startx;
	int starty;
	int endx;
	int endy;
}LI;
	LI a[105],hold;
int find (int m,int t,int n){
	int i=m+1;
	int j=m;
	while(i<n){
		if(a[i].startx==a[j].endx&&a[i].starty==a[j].endy){
			j=i;
			t++;
		}
		i++;
	}
	return t;
}
int main(){
	int n,i,j,x,y,len,max=-1;
	int num[105]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].startx,&a[i].starty,&a[i].endx,&a[i].endy);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j].startx>a[j+1].startx){
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
			}
		}
	}
	for(i=0;i<n;i++){
		len=find(i,1,n);
		if(len>max){
			max=len;
			x=a[i].startx;
			y=a[i].starty;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

