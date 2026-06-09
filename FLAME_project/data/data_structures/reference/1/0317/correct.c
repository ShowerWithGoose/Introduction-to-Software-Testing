#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int book[100]={0};
int a[100]={0};
void fullArray(int step,int n){
	if(step==n){
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(book[i]==0){
				a[step]=i;
				book[i]=1;
				fullArray(step+1,n);
				book[i]=0;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	fullArray(0,n);

	return 0;
}


