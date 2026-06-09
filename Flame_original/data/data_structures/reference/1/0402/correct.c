#include <stdio.h>
int a[12];
int book[12];
int n;
void DFS(int step){
	int i;
	if(step==n+1){
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	else{
		for(i=1;i<=n;i++){
			if(book[i]==0){
				a[step]=i;
				book[i]=1;
				DFS(step+1);
				book[i]=0;
			}
		}
	}
	return ;
} 
int main(){
	scanf("%d",&n);
	DFS(1);
	return 0;
}

