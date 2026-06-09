#include<stdio.h>
#include<string.h>
int n,a[10]={1,2,3,4,5,6,7,8,9,10},b[10]={0};
void f(int k){
	int i=0;
	if(k==n)
	{
		for(i=0;i<n;i++)
		printf("%d%c",a[i],i==n-1?'\n':' ');
	}
	for(i=0;i<n;i++)
		if(!b[i])
		{
			b[i]=1;
			a[k]=i+1;
			f(k+1);
			b[i]=0;
		}
}
int main (){
	scanf("%d",&n);
	f(0);
	return 0;
}

