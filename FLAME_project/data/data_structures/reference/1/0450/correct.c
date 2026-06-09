#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int a[20],book[20];

int Q(int n,int d){
	int i,j;
	
	for(i=1;i<=n;i++){
		if(book[i]==0){
			a[d-1]=i;
			book[i]=1;
			Q(n,d+1);
			book[i]=0;
		}
	}
	if(d==n){
		for(j=0;j<n;j++){
			printf("%d ",a[j]);
		}
		putchar('\n');
		return;
	}
	
} 

int main()
{
	int n;
	scanf("%d",&n);
	Q(n,1);
	
	return 0;
}

