#include<stdio.h>
void qp(int *a,int *b,int m,int n){
	int i=0;
	for(i=1;i<=m;i++){
		if(b[i]==0){
			b[i]=1;
			a[n]=i;
			qp(a,b,m,n+1);
			b[i]=0;
		}
	}
	if(n==m+1){
		for(i=1;i<=m;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
}
int main()
{
    int a[100]={0},b[100]={0};
	int m; 
	scanf("%d",&m);
	qp(a,b,m,1);
    return 0;
}



