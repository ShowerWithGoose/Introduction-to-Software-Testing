#include<stdio.h>
#include<string.h>
char r[10];
int f[11];
int N;
void pl(int, int);
int main()
{
	int k;
	for(k=0;k<11;k++)
	{ 	
		f[k]=0;
	}
 	int  i;
	scanf("%d", &N);
 	pl(0, N);
}
void pl(int m, int n)
{ 
 	int i,j;
 	if(n == 0)
 	{
 		 r[m] = '\0';
  		for(j = 1; j <= N; j++)
  		{
 		  printf("%c ",r[j-1]);
 		}
  		printf("\n");
  		return;
 	}
 	for(i = 1; i <= N; i++)
	{
  		if(f[i] == 0)
		{
  			f[i] = 1;
  			r[m] = '0' + i;
  			pl(m+1, n-1);
  			f[i] = 0;
 		}
	}
}




