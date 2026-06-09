#include<stdio.h>
int data[15];
int num[15];
int mark[15]={0};
int n;
void f(int a);
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		data[i]=i;
	}
	f(1);
}
void f(int k){
	int i,j,flag;
	if(k==n+1){
		for(i=1;i<k;i++){
			if(i==k-1) printf("%d\n",num[i]);
			else printf("%d ",num[i]);
		}
		return;
	}
	for(i=1;i<=n;i++){
		flag=1;
		for(j=1;j<k;j++){
			if(num[j]==data[i]) flag=0;
		}
			if(flag==1){
				num[k]=data[i];
				f(k+1);
			
			}
		}
	}



