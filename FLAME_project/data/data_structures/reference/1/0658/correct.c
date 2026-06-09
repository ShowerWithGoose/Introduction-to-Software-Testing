#include<stdio.h>
int ans[15];
void rec(int i,int m,int *a){
	if(i==m+1){
		for(int k=1;k<=m;k++) printf("%d ",ans[k]);
		printf("\n");		
		return;
	}
	for(int k=1;k<=m;k++){
		if(a[k]!=0){
			ans[i]=k;
//			printf("%d ",a[k]);
			a[k]=0;
		}
		else continue;
		rec(i+1,m,a);
		a[k]=k;
	}
}
int main(){
	int m;
	scanf("%d",&m);
	int a[m+1];
	for(int i=1;i<=m;i++) a[i]=i;
	rec(1,m,a);
} 

