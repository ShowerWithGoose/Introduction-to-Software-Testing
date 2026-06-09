#include <stdio.h>
#include <string.h>
int a[11];
int used[11]={0};
void F(int i,int j)
{
	int k,m;
	for(k=1;k<=j;k++)
	{
		if(!used[k]){
			used[k]=1;
			a[i]=k;
			if(i==j)
			{
				for(m=1;m<=j;m++)
				printf("%d ",a[m]);
				printf("\n");
			 }
			 else{
			 	F(i+1,j);
			 }
			 used[k]=0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	F(1,n);	
	return 0;
 } 
		

