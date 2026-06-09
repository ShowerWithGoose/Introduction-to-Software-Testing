#include<stdio.h>
struct xian
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main(){
	struct xian x[100];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x[i].x1,&x[i].y1,&x[i].x2,&x[i].y2);
	}
	int t1,t2,t3,t4,ans1,ans2,sum=1,ans3=0;
	int j,flag=0;
	for(i=0;i<n;i++){
		t1=x[i].x2; t2=x[i].y2; t3=x[i].x1; t4=x[i].y1;
		for(j=0;j<n;j++){
			if(t1==x[j].x1&&t2==x[j].y1){
				sum++;
				t1=x[j].x2;
				t2=x[j].y2;
				flag=1;
			}
			if(flag==1){
				flag=0;
				j=-1;
			}
		}
		if(sum>ans3){
			ans3=sum;
			ans1=t3;
			ans2=t4;
		}
		sum=1;
	}
	printf("%d %d %d",ans3,ans1,ans2);
	return 0;
} 

