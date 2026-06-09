#include<stdio.h>
#include<string.h>

int c[15],b[15],flag[15];
int line(int k,int n){
	int i,j,m;
	if(k==n){
		for(m=0;m<n;m++)
		printf("%d ",b[m]);
		printf("\n");
	}
	else{
	
	for(j=0;j<n;j++){
		if(flag[j]==0){
			b[k]=c[j];
			flag[j]=1;
			line(k+1,n);
			flag[j]=0;
		}
	}
	
}}
int main(){
	int n,i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		c[i]=i+1;
	}
	k=0;
	line(k,n);
	return 0;
}

