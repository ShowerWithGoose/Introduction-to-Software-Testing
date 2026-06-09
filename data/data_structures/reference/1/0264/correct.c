#include<stdio.h>
int A[12],box[12],n;
void f(int k){
	int i;
	if(k>n){
		for(i=1;i<=n;i++)
			printf("%d ",A[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(box[i]){
			A[k]=i;
			box[i]=0;
			f(k+1);
			box[i]=1;
		}
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=10;i++)
		box[i]=1;
	f(1);	
	return 0;	
} 



