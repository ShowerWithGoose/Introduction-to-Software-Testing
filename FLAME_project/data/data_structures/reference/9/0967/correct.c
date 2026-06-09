#include <stdio.h>
struct max{
	int xa,xb,ya,yb,zs;
}num[101],max;
void zc(int qs,int dq,int end,int sum){
	int i;
	
	for(i=0;i<end;i++){
		if(num[dq].xb==num[i].xa&&num[dq].yb==num[i].ya){
			sum++;
			zc(qs,i,end,sum);
		}
	}
	if(sum>max.zs){
		max.zs=sum;
		max.xa=num[qs].xa;
		max.xb=num[qs].xb;
		max.ya=num[qs].ya;
		max.yb=num[qs].yb;
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&num[i].xa,&num[i].ya,&num[i].xb,&num[i].yb);
	}
	for(i=0;i<n;i++){
		zc(i,i,n,1);
	}
	printf("%d %d %d",max.zs,max.xa,max.ya);
	return 0;
 } 

