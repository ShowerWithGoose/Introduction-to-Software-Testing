#include<stdio.h>
int n,card[11],box[11];

void place(int step);

int main(){
	
	scanf("%d",&n);
	place(1);
	
	return 0;
}

void place(int step){
	int i;
	if(step==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",box[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(card[i]==0){
			box[step]=i;
			card[i]=1;
			place(step+1);
			card[i]=0;
		}
	}
	return ;
}



