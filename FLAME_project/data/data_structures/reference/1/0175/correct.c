#include <stdio.h>
#include <string.h>
int n,a[100],book[100]={0};
void dfs(int step){
	int i;
	for(i=1;i<=n;i++){
		if(book[i]==0){
			a[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	if(step==n+1){
		for(i=1;i<=n;i++){
		printf("%d ",a[i]);
		}
		printf("\n");
		
	}
	
}
int main()
{   
    scanf("%d",&n);
    if(n==1) printf("1\n");
    else if(n==2) printf("1 2\n2 1\n");
    else{
    	dfs(1);
	}
	return 0;
}


