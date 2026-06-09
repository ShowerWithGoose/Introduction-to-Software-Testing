#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	int a[100][4]={0};
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max=0,count=1,x=a[0][0],y=a[0][1];
	for(i=0;i<n;i++){
		count=1;
		int k=i;
		for(j=0;j<n;j++){
			if(j==k){
				continue;
			}
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1]){
				k=j;
				j=-1;
				count++;
				continue;
			}
			if(j==n-1){
				break;
			}
		}
		if(count>max){
			x=a[i][0];
			y=a[i][1];
			max=count;
		}	
	}
	printf("%d %d %d",max,x,y);
	return 0;
} 

