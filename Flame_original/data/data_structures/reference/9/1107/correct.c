#include<stdio.h>
struct item{
	int x1;
	int x2;
	int y1;
	int y2;
}list[105];

int main(){
	int n;
	struct item temp;
	int cnt;
	int xp,yp;
	int nmax=0;
	int cmax;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(list[i].x1>list[j].x1) {
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cnt=1;
		xp=list[i].x2;
		yp=list[i].y2;
		for(int j=i+1;j<=n;j++){
			if(xp==list[j].x1&&yp==list[j].y1){
				xp=list[j].x2;
				yp=list[j].y2;
				cnt++;
			}
		}
		if(cnt>nmax){
			nmax=cnt;
			cmax=i;
		}
	}
	printf("%d %d %d",nmax,list[cmax].x1,list[cmax].y1);
	return 0;
	
	
}
