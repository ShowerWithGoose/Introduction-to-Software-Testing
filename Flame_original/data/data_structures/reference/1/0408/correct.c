#include <stdio.h>
#include <string.h>
int hash[10],b[15];
char a[11];
int N;
void arrange(int m,int n);
int main()
{
	scanf("%d",&N);
	arrange(0,N);
	
	return 0;
}
void arrange(int m,int n)
{
	int i,j;
	if(n==0)
		{
			a[m]='\0';
			for(j=0;a[j]!='\0';j++)
			{
				b[j]=a[j]-'0';
			}
			for(j=0;a[j]!='\0';j++)
			{
				printf("%d ",b[j]);
			}
			printf("\n");
			return;
		}
	for(i=1;i<=N;i++)
	{
		if(hash[i]==0)
		{
			hash[i]=1;
			a[m]='0'+i;
			arrange(m+1,n-1);
			hash[i]=0;
		}
	}
}





