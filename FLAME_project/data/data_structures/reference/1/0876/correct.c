#include <stdio.h>
#include <stdlib.h>

int box[12],hand[12];
void index(int m, int n);
int main(){
	int n;
	scanf("%d",&n);
	index(1,n);
	return 0;
} 

void index(int m, int n){
	int i,j,k;
	if(m>n){
		for(j=1;j<n;j++){
			printf("%d ",box[j]);
		}
		printf("%d\n",box[j]);
		return;
	}
	for(i=1;i<=n;i++){
		if(hand[i]==0){
			box[m]=i;
			hand[i]=1;
			index(m+1,n);
			hand[i]=0;
		}
	}
}

