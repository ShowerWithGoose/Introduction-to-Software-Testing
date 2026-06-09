#include <stdio.h>
void rank(int m, int n); 				  
int N,mark[15];
int a[15];
int main ()
{
	scanf ("%d", &N);	
	rank(0,N);	
	return 0;
}
void rank(int m, int n)
{
	int i;
	if( n == 0)
	{ 
		int j;
		for(j=0;j<N;j++)
		{
			printf("%d ",a[j]);
		}	
		puts("");
		return;
	}
	for(i=1; i<=N; i++)
		if(mark[i] == 0 )
		{
			mark[i] = 1; 
			a[m] = i;  	
			rank(m+1,n-1); 
			mark[i] = 0;
		}
}



