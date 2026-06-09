#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}a[1001];

int main(){
	int n,i,j;
	struct line tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		 scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i].x1>a[j].x1){
			    tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			
			}
		}
	}
	
	int max=1,x=0,y=0;
	
	for(i=0;i<n;i++){
		int sum=1,p,q;
		p=a[i].x2;
		q=a[i].y2;
		for(j=i+1;j<n;j++){
			if(p==a[j].x1&&q==a[j].y1){
				sum++;
				p=a[j].x2;
				q=a[j].y2;
			}
		}
		if(sum>max){
			max=sum;
			x=a[i].x1;
			y=a[i].y1;
		}
	}
	printf("%d %d %d\n",max, x,y);
	return 0;
}

