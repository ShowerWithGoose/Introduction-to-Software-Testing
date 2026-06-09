#include<stdio.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int tou;
	int wei;
};
struct line point[220];

int islianjie(int i,int j){
	if((point[i].x2==point[j].x1)&&(point[i].y2==point[j].y1)) return 1;
	return 0;
}

int jishu(int i){
	int q,c=1;
	for(q=i;point[q].wei!=0;c++){
		q=point[q].wei;
	}
	return c;
}

int main() {
	int n,i,j,count=1,z=1,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(islianjie(i,j)==1){
				point[i].wei=j;
				point[j].tou=i;
				break;
			}
		}
	}
	for(i=1;i<=n;i++){
		if((point[i].tou==0)&&(point[i].wei!=0)){
			c=jishu(i);
			if(c>count){
				count=c;
				z=i;
			}
		}
	}
	printf("%d %d %d",count,point[z].x1,point[z].y1);
	return 0;
}

