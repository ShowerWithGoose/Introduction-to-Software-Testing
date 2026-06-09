#include <stdio.h>
#include <string.h>
int shu[110] = { 0 };
int yong[11] = { 0 };
void jishu(int m, int n);
int N;
int main()
{
	scanf("%d", &N);
	jishu(0,N);
	return 0;
}
void jishu(int m, int n)
{
	int i;
	int temp;
	if (n == 0)
	{
		for (temp = 0; shu[temp] != 0; temp++)
		{
			printf("%d ", shu[temp]);
		}
		printf("\n"); temp = 0;
		return;
	}
	
	
		for (i = 1; i <= N; i++)
		{
			if (yong[i] == 0)
			{
				yong[i] = 1;
				shu[m] = i;
				jishu(m + 1, n - 1);
				yong[i] = 0;
			}
		}
	
}



