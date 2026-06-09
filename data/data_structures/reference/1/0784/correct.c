#include<stdio.h>
int num[11]={100,1,2,3,4,5,6,7,8,9,10};
int n;
void p(int num[11]){
	int temp;
	for(int i=n;i>=1;i--){
		if(num[i-1]<num[i]){
			for(int j=n;j>=i;j--){
				if(num[j]>num[i-1]){
					temp=num[j];
					num[j]=num[i-1];
					num[i-1]=temp;
					break;
				}	
			}
			for(int j=i;j<=(i+n)/2;j++){
				int temp=num[j];
				num[j]=num[n+i-j];
				num[n+i-j]=temp;
			}
			for(int i=1;i<=n;i++)
				printf("%d ",num[i]);
			printf("\n");
			p(num);
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	printf("\n");
	p(num);
	return 0;
}



