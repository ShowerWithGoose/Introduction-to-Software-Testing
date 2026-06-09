#include<stdio.h>
int n,m=0;
int a[101],b[101]={};

void quanpai(int x){
	int i;	
	if(x==0){
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");

	}
	else{
		for(i=1;i<=n;i++){
			if(b[i]==0){
				b[i]=1;
				a[m]=i;
				m++;
				quanpai(x-1);
				b[i]=0;
				m--;	
			}				
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	quanpai(n);
	return 0;
}



