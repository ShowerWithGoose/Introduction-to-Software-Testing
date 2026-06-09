#include<stdio.h>
int n,c;
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}li[1000];
int f(int x,int y){
	int i;
	for(i=1;i<=n;i++){
		if(x==li[i].x1&&y==li[i].y1){
			c++;
			f(li[i].x2,li[i].y2);
		}
	}
	return c;
}

int main(){
	int j,sum;
//	struct line li[1000];
	scanf("%d",&n);
	int i,tmp,max=-1;
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&li[i].x1,&li[i].y1,&li[i].x2,&li[i].y2);
	}
	for(i=1;i<=n;i++){
		c=0;
		sum=f(li[i].x2,li[i].y2)+1;
//		printf("%d\n",sum);
		if(sum>max){
			max=sum;
			tmp=i;
		}
	}
	printf("%d %d %d",max,li[tmp].x1,li[tmp].y1);
	return 0;
} 

