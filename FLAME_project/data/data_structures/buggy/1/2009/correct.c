#include<stdio.h>
int used[11] = {0}, N;
char re[31];
void rank(int n, int loc);
int main()
{
	int n;
	scanf("%d", &N);
	re[2*N+1] = '\0' ;
	rank(N, 0);

    return 0;
}

void rank(int n, int loc)
{
	
	if(n == 0)
	{
		puts(re);
		return;
	}  
	else
	{
		for(int i = 1; i <= N; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				re[loc*2] = '0' + i;
				re[loc*2+1] = ' ';
				rank(n-1, loc + 1);
				used[i] = 0;
			}
			
		}
	}
}



