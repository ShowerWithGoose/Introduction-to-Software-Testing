#include<stdio.h>
struct duan{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	int n,i,j;
	struct duan a[100],tp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].x1);
		scanf("%d",&a[i].y1);
		scanf("%d",&a[i].x2);
		scanf("%d",&a[i].y2);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j].x1>a[j+1].x1)
			{
				tp=a[j];
				a[j]=a[j+1];
				a[j+1]=tp;
			}
		}
	}
	int amount=1,num,x=a[0].x1,y=a[0].y1,xo,yo,xt,yt,sign[100]={0};
	for(i=0;i<n;i++){
		if(sign[i]==1)
		  continue;
		num=1,xo=a[i].x1,yo=a[i].y1,xt=a[i].x2,yt=a[i].y2;
		sign[i]=1;
		for(j=i+1;j<n;j++){
			if(a[j].x1==xt&&a[j].y1==yt){
				num++;
				xt=a[j].x2,yt=a[j].y2;
				sign[j]=1;
			}
		}
		if(num>amount)
		  {
		  	amount=num;
		  	x=xo;
		  	y=yo;
		  }
	}
	printf("%d %d %d",amount,x,y);
	return 0;
}

