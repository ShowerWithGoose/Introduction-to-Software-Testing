#include <stdio.h>
#include <string.h>

int ans[15],flag[15];
void Quanpl(int l,int n);

int main(){
	int n,i;
	scanf("%d",&n);
	Quanpl(0,n);
	return 0;
}

void Quanpl(int l,int n){
	int i;
	if(l==n){
		for(i=0;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	else{
		for(i=0;i<n;i++){
			if(flag[i]==0){
				ans[l]=i+1;
				flag[i]=1;
				Quanpl(l+1,n);
				flag[i]=0;
			}
		}
	}
}



