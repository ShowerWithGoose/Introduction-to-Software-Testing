#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}a[105],temp;
int main(){
	int num,i,j;
	int max=0;
	int mina,minb;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	take(num,a,temp);
	for(i=0;i<num;i++){
		int n=i;int count=1;
		for(j=i+1;j<num;j++){
			if(a[n].x2==a[j].x1){
				if(a[n].y2==a[j].y1){
					count++;
					n=j;
				}
			}
		}
		if(count>max){
			max=count;
			mina=a[i].x1;
			minb=a[i].y1;
		}
}
	printf("%d %d %d",max,mina,minb);
	return 0;
}
void take(int num,struct line a[105],struct line temp){
	int i=0,j;
	for(i=0;i<num;i++){
		for(j=i+1;j<num;j++){
			if(a[i].x1>a[j].x1){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

