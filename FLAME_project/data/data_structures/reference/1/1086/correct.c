#include<stdio.h>
int a[11]={0};
char s[12];
void f(int m,int n); 				  
int N;
int main()
{
	scanf ("%d",&N);	
	f(0,N);	
	return 0;
}
void f(int m,int n)
{
	int i,j;
	if(n==0)
	{ 
		s[m]='\0';
		printf("%c",s[0]);
		for(j=1;j<m;j++)
		{
			printf(" %c",s[j]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++)
		if(a[i]==0 )
		{
			a[i]=1;
			s[m]='0'+i;
			f(m+1,n-1);
			a[i]=0;
		}
}

