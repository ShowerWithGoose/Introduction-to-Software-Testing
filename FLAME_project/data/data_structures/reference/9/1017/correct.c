#include<stdio.h>
#include<stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
	int n,i;
		int k=0;
	struct line xian[101];
	int sum[101][3]={0};

void lian(struct line  );
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %d %d %d %d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
	}
	for(i=0;i<n;i++){
		lian(xian[i]);
	}

	int sum1=sum[0][0];
	int j,j0=0;

	for( j=0;j<n;j++){
		for(int e=0;e<2;e++){
			if(sum[j][e]>sum1){
			sum1=sum[j][e];
			j0=j;
			}
	}
	}
	printf("%d %d %d",sum1+1,xian[j0].x1,xian[j0].y1);
	return 0;
	
}
void lian(struct line a ){
	int e=0;
	
	for(int j=0;j<n;j++){
			if(a.x2!=xian[j].x1&&a.y2!=xian[j].y1)
			{
			e++;
			}
	}
	if(e==n)
	{
		return;
		
	}
	else{
	for(int j=0;j<n;j++){
		if(a.x2==xian[j].x1&&a.y2==xian[j].y1)
		{
		sum[i][k]++;
		lian(xian[j]);
		
		}
	}
}

}














