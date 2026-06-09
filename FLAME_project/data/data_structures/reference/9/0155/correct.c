#include<stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}a[100];
int main(){
	int n,i=0,m=0,b=0,j=0,k=0,tx,ty,tm,q=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(j=0;j<n;j++){
		tx=a[j].x2;
		ty=a[j].y2;
		for(k=0;k<n;k++){
			if((tx==a[k].x1)&&(ty==a[k].y1)){
				i=0;
				tm=2;
				tx=a[k].x2;
				ty=a[k].y2;
				while(i!=1){
					i=1;
					for(q=0;q<n;q++){
						if((tx==a[q].x1)&&(ty==a[q].y1)){
							tm++;
							tx=a[q].x2;
				            ty=a[q].y2;
				            i=0;
						}
					}
				}
				if(tm>m){
					m=tm;
					b=j;
				}
			}
		}
	}
	printf("%d %d %d",m,a[b].x1,a[b].y1);
	return 0;
}

