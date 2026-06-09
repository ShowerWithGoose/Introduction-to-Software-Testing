#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int a[1000];
void push(int i,int j,int m){
	int temp=a[i];
	a[i]=a[m];
	a[m]=temp;
	i++;
	while(i<j){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++,j--;
	}
	return ;
}
void print(int n,int k){
	int i;
	if(k==n){
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(i=k;i<=n;i++){
		print(n,k+1);
		if(i<n)
			push(k,n,n-i+k); 
	}
	return ;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i]=i;
	print(n,1);
	return 0;
}




