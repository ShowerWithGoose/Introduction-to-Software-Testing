#include<stdio.h>
#include<string.h>
int a[15],i,j,n;
int f(int n)
{
	int x=1,b;
	for(b=1;b<=n;b++){
		x*=b;
	}
	return x;
}//n!
void print()
{
	int b;
	for(b=1;b<=n;b++){
		printf("%d ",a[b]);
	}
	printf("\n");
}
void h()
{
	for(i=n-1;i>=1;i--){
		if(a[i]<a[i+1])
			break;
	}
	int k=i,low=i+1;
	for(i=k+1;i<=n;i++){
		if(a[i]>a[k]&&a[i]<a[low])
			low=i;
	}
	int temp;
	temp=a[k];
	a[k]=a[low];
	a[low]=temp;
	for(j=k+1,i=n;i>j;i--,j++){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
int main()
{
	int i;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	print();
	for(i=2;i<=f(n);i++){
		h();
		print();
	}
	return 0;
}



