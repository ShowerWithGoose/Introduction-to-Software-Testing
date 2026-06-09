#include<stdio.h>
int a[15];
int hf(int m,int n,int a[])
{
	int k,l,flag=0;
	for(k=1;k<=n;k++){
		a[k]=m%10;
		m/=10;
	}
	for(k=1;k<=n;k++){
		for(l=1;l<=n;l++){
			if(a[l]==k){
			    flag++;	
			    break;
			}
		}
	}
	if(flag==n) return 1;
	else return 0;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int k=1;
	int n1=n-1;
	while(n1--) k*=10;
	int m,s;
	for(m=k;m<k*10;m++){
		if(hf(m,n,a)){
	    for(s=n;s>0;s--) printf("%d ",a[s]);
	    printf("\n");
	    } 
	}
	return 0;
}



