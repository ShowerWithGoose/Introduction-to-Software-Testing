#include<stdio.h>
#include<string.h>
int A[10];
void print_permutation(int *a,int cur,int n)
{
	if(cur==n){
		for(int i=0;i<n;i++)
		{
			if(i)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}else{
		for(int i=1;i<=n;i++)
		{
			int ok=1;
			for(int j=0;j<cur;j++)
			{
				if(a[j]==i)ok=0;
			}
			if(ok){
				a[cur]=i;
				print_permutation(a,cur+1,n);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	print_permutation(A,0,n);
}



