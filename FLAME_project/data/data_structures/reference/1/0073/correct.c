#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int n;
int count[10],term[10];
void Deepfind(int a){
	int i;
	if(a==n){
		for(i=1;i<=n;i++){
			printf("%d ",term[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(count[i]==0){
		
		term[a+1]=i;
		count[i]++;
		
		Deepfind(a+1);
		count[i]--;
		}
	}
	
	
}




int main(){


scanf("%d",&n);
Deepfind(0);

}




