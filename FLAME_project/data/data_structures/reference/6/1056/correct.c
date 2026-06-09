#include<stdio.h>
int main()
{
	int a[100],top=-1,n,m;
	while(1)
	{
	scanf("%d",&n);
		if(n==1){
			scanf("%d",&m);
			++top;
			a[top]=m;
		} 
		if(n==0){
			if(top>=0){
			printf("%d ",a[top]);
			top--;
			}else{
				printf("error ");
			}
		}
		if(n==-1){
			break;
		}
	 } 
return 0;
}


