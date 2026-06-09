#include<stdio.h>
int n,a[100002],card[100002];
void dfs(int box)
{
	int i;
	if(box==n+1){
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return ;
    }
	for(i=1;i<=n;i++){
	  if(!card[i])
	  {
	  	 a[box]=i;
	  	 card[i]=1;
	  	 dfs(box+1);
		 card[i]=0; 
	  }
    }
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}



