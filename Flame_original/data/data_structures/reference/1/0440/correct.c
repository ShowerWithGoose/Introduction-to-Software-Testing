#include<stdio.h> 
#include<string.h>

int n,k,flag[15],ch[15];


void prin(int n){
	int i,j;
	if(n){
		for(i=1;i<=k;i++){
			if(!flag[i]){
				flag[i]=1;
				ch[k-n+1]=i;
				prin(n-1);
				flag[i]=0;
			}
		}
	}else{
		for(j=1;j<=k;j++)
		printf("%d ",ch[j]);
		printf("\n");
	}
}
int main(){
	scanf("%d",&k);
	prin(k);
	return 0;
}

