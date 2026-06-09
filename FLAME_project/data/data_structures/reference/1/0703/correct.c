#include<stdio.h>
int num[15],used[15];
void arr(int,int);
int main(){
	int n;
	scanf("%d",&n);
	arr(1,n);
	return 0;
}
void arr(int m,int n){
	int i,j;
	for(i=1;i<=n;i++){
		if(!used[i]){
			num[m]=i;
			used[i]=1;
			if(m==n){
				for(j=1;j<=n;j++){
					printf("%d ",num[j]);
				}
				printf("\n");
			}
			else{
				arr(m+1,n);
			}
			used[i]=0;
		}
	}
}


