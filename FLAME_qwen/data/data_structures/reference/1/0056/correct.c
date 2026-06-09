#include<stdio.h>

int nums[20]={0};
int use[20]={0};

int n;

int main(){
	scanf("%d",&n);
	Cal(0);
}

void Cal(int doneCount){
	if(doneCount==n){
		for(int i=0;i<n;i++)printf("%d ",nums[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			use[i]=1;
			nums[doneCount]=i;
			Cal(doneCount+1);
			use[i]=0;
		}
	}
}





