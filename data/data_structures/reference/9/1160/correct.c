#include <stdio.h>
#define TYPE int
void swap(TYPE *a, TYPE *b)
{
	*a ^= *b ^= *a ^= *b;
}
void bSort(TYPE ax[], TYPE ay[], TYPE bx[], TYPE by[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ax[j] > ax[j + 1])
			{
				swap(&ax[j], &ax[j + 1]);
				swap(&ay[j], &ay[j + 1]);
				swap(&bx[j], &bx[j + 1]);
				swap(&by[j], &by[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
	return;
}

int main()
{
	int n;
	int ax[100];
	int ay[100];
	int bx[100];
	int by[100];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&ax[i],&ay[i],&bx[i],&by[i]);
	}
	bSort(ax, ay, bx, by, n);
	int maxlen = 0;
	int MINX, MINY;
	int tag[100] = {0};
	for (int i = 0; i < n; i++)
	{
		if (tag[i])
		{
			continue;
		}
		int op = i;
		tag[op] = 1;
		int len = 1;
		int minx = ax[i];
		int miny = ay[i];
		int x_to_right = bx[i];
		int y_to_right = by[i];
		for (int j = 0; j < n; j++)
		{
			if (tag[j] == 0 && ax[j] == x_to_right && ay[j] == y_to_right)
			{
				len++;
				tag[j] = 1;
				x_to_right = bx[j];
				y_to_right = by[j];
			}
		}
		if (len > maxlen)
		{
			maxlen = len;
			MINX = minx;
			MINY = miny;
		}
	}
	printf("%d %d %d",maxlen,MINX,MINY);
	

	return 0;
}
