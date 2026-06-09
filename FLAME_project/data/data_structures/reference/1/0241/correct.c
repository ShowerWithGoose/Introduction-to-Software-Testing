#include <stdio.h>
#include <string.h>
int count[110] = { 0 };
int shu[11] = { 0 };
void jishu(int m, int n);
int t;
int main()
{
	scanf("%d", &t);
	jishu(0,t);
	return 0;
}
void jishu(int m, int n)
{
	int i;
	int temp;
	if (n == 0)
	{
		for (temp = 0; count[temp] != 0; temp++)
		{
			printf("%d ", count[temp]);
		}
		printf("\n"); temp = 0;
		return;
	}
	
	
		for (i = 1; i <= t; i++)
		{
			if (shu[i] == 0)
			{
				shu[i] = 1;
				count[m] = i;
				jishu(m + 1, n - 1);
				shu[i] = 0;
			}
		}
	
}



