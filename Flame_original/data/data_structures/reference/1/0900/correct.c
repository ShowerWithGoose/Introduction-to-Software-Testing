#include<stdio.h>
#include<string.h>
char result[10];
int mark[11] = {0};
int N;
void berank(int, int);
int main()
{
	int  i;
	scanf("%d", &N);
	berank(0, N);
}
void berank(int m, int n)
{	
	int i,j;
	if(n == 0)
	{
		result[m] = '\0';
		for(j = 1; j <= N; j++)
		{
			printf("%c ",result[j-1]);
		}
		printf("\n");
		return;
	}
	
	for(i = 1; i <= N; i++)
	{
		if(mark[i] == 0){
		mark[i] = 1;
		result[m] = '0' + i;
		berank(m+1, n-1);
		mark[i] = 0;
	}
	}

}



