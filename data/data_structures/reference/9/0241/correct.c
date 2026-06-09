#include <stdio.h>
#include <string.h>
int a[200][4];
int main()
{
	int n;
	int i;
	int temp0, temp1, temp2, temp3;
	int t;
	int count = 0;
	int max = 0;
	int zuobiao1, zuobiao2;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	}
	for (i = 0; i < n; i++)
	{
		for (t = 0; t < n - 1 - i; t++)
		{
			if (a[t][0] > a[t + 1][0])
			{
				temp0 = a[t][0];
				temp1 = a[t][1];
				temp2 = a[t][2];
				temp3 = a[t][3];
				a[t][0] = a[t + 1][0];
				a[t][1] = a[t + 1][1];
				a[t][2] = a[t + 1][2];
				a[t][3] = a[t + 1][3];
				a[t + 1][0] = temp0;
				a[t + 1][1] = temp1;
				a[t + 1][2] = temp2;
				a[t + 1][3] = temp3;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		t = i;
		count = 0;
		for (int ling = i + 1; ling < n; ling++)
		{
			if (a[t][2] == a[ling][0] && a[t][3] == a[ling][1])
			{
				t = ling;
				count++;
			}
		}
		if (max < count)
		{
			max = count;
			zuobiao1 = a[i][0];
			zuobiao2 = a[i][1];
		}
	}
	printf("%d %d %d", max + 1, zuobiao1, zuobiao2);
}

