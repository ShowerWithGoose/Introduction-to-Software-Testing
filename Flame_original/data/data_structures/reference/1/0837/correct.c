#include<stdio.h>
int n;
int used[13]={0},c[13];
void op(int f)
{
 if(f==n+1)
 {
 	
 for(int i=1;i<=n;i++)
 printf("%d ",c[i]);	
 printf("\n");
 return ;	
 	
 }
 for(int i=1;i<=n;i++)	
	if(used[i]==0)
	{
		c[f]=i;
		used[i]=1;
		op(f+1);
		used[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	op(1);
	return 0;
}

