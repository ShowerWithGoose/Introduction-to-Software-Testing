#include<stdio.h>
int main(){
	int n=0,i=0,j=0,QX[100]={0},QY[100]={0},MX[100]={0},MY[100]={0},sum[100]={1},q=0;
	struct line{
		int qx[100];
		int qy[100];
		int mx[100];
		int my[100];
	};
	struct line l[100];
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",l[i].qx,l[i].qy,l[i].mx,l[i].my);
	}
	for(i=0;i<n;i++){
		QX[i]=*l[i].qx;
		QY[i]=*l[i].qy;
		MX[i]=*l[i].mx;
		MY[i]=*l[i].my;
		for(j=0;j<n;j++){
			if(QX[i]==*l[j].qx&&QY[i]==*l[j].qy&&MX[i]==*l[j].mx&&MY[i]==*l[j].my){
				
			}
			else if(QX[i]==*l[j].mx&&QY[i]==*l[j].my){
				sum[i]++;
				QX[i]=*l[j].qx;
				QY[i]=*l[j].qy;
				j=-1;
			}
			else if(MX[i]==*l[j].qx&&MY[i]==*l[j].qy){
				sum[i]++;
				MX[i]=*l[j].mx;
				MY[i]=*l[j].my;
				j=-1;
			}			
		}
	}
	for(i=1;i<n;i++){
		if(sum[i]>sum[0]){
			sum[0]=sum[i];
			q=i;
		}
	}
	printf("%d %d %d\n",sum[0],QX[q],QY[q]);
	return 0;
} 

