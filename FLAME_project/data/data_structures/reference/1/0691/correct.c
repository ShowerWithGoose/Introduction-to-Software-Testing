#include<stdio.h>
int ans[15];
int flag[15];
void qpl(int a,int n)//a是正在找的数的位置 
{   if(a==n)
	{
	    int j;
		for(j=0;j<n;j++) printf("%d ",ans[j]);
		printf("\n");
	}
	int i;
	for(i=1;i<=n;i++)
	{   
	
		if(flag[i]!=1)
		{
			ans[a]=i;
		    flag[i]=1;
		    qpl(a+1,n);
			flag[i]=0;
		}
		
	
	 } 
}
int main()
 {
	int n;
	scanf("%d",&n);
    qpl(0,n);
	return 0;
}


