#include<stdio.h>
int m[10]={0};
int s[11];
void r(int a,int b);
int n;
int main(){
	scanf("%d",&n);
	r(0,n);
	return 0;
}
void r(int a,int b){
	int i,j;
	
	for(i=0;i<n;i++){
		if(m[i]==0){
			m[i]=1;
			s[a]=i+1;
			r(a+1,b-1);
			m[i]=0;
		}
	}
	if(b==0){
		for(j=0;j<n;j++){
			printf("%d ",s[j]);
		}
		printf("\n");
		return; 
	}
}

