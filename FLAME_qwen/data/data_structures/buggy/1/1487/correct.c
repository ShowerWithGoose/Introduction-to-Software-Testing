#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void swap1(int s[], int a, int b)
{
	int i,t;
    t = s[b];
    for (i=b-1; i>=a; i--)
	{
        s[i+1] = s[i];
    }
    s[a] = t;
 }
 
 void swap2(int s[], int a, int b){
    int i,t;
    t = s[a];
    for (i=a; i<b; i++)
	{
        s[i] = s[i+1];
    }
    s[b] = t;
}
 
void perm(int s[], int m, int n)
{
	int i, j, t;
	if(m==n)
	{
		for(i=0;i<=n;i++)
		{
			printf("%d ", s[i]);
		}
		printf("\n");
	}
	for(j=m;j<=n;j++)
	{
		swap1(s, m, j);
		perm(s, m+1, n);
		swap2(s, m, j);
	}
}

int main()
{
	int N, i, s[10000];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		s[i] = i+1;	
	 } 
	
	perm(s, 0, N-1);
	 
	return 0;
}




