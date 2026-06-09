#include<stdio.h>
struct duan{
	int x1;
	int y1;
	int x2;
	int y2;
	int sum;
}xian[101],p;
int main(){
	int i=0,N,j=0,max=0,m=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&xian[i].x1);
		scanf("%d",&xian[i].y1);
		scanf("%d",&xian[i].x2);
		scanf("%d",&xian[i].y2);
		xian[i].sum=1;
	}
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(xian[i].x1>xian[j].x1){
				p=xian[i];
				xian[i]=xian[j];
				xian[j]=p;
			}
			else if(xian[i].x1==xian[j].x1&&xian[i].y1>xian[j].y1){
				p=xian[i];
				xian[i]=xian[j];
				xian[j]=p;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j==i)
			{
				continue;
			}
			else
			{
				if(xian[j].x1==xian[i].x2&&xian[j].y1==xian[i].y2)
				{
					xian[i].x2=xian[j].x2; 
					xian[i].y2=xian[j].y2;
					xian[i].sum+=xian[j].sum;
					xian[j].x1=0,xian[j].y1=0,xian[j].x2=0,xian[j].y2=0,xian[j].sum=0;
				}
			}
		}
	}
	max=xian[0].sum;
	for(i=0;i<N;i++){
		if(xian[i].sum>max){
		max=xian[i].sum;
		m=i;
	    }
	}
	printf("%d %d %d",xian[m].sum,xian[m].x1,xian[m].y1);
	return 0;
} 

