/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/

#include <stdio.h>

void swap(int*, int*);
void perm(int [], int, int);

int n;

int main()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	scanf("%d", &n);
	perm(array, 0, n - 1);
	
	return 0;
}

void swap(int *x, int *y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

void perm(int a[], int l, int r)
{
	int i, j;
	if(l == r)
	{
		for(i = 0; i <= r; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	else
	{
		for(j = l; j <= r; j++)
		{
			swap(&a[j], &a[l]);
			int a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3], a4 = a[4], a5 = a[5], a6 = a[6], a7 = a[7], a8 = a[8], a9 = a[9];
			int m, k, swapFlag, hold;
			for(m = 1; m < n - l - 1; m++)
			{
				swapFlag = 0;
				for(k = l + 1; k < n - m; k++)
				{
					if(a[k] > a[k + 1])
					{
						swapFlag = 1;
						hold = a[k];
						a[k] = a[k + 1];
						a[k + 1] = hold;
					}
				}
				if(swapFlag == 0)
					break;
			}
			perm(a, l + 1, r);
			a[0] = a0;
			a[1] = a1;
			a[2] = a2;
			a[3] = a3;
			a[4] = a4;
			a[5] = a5;
			a[6] = a6;
			a[7] = a7;
			a[8] = a8;
			a[9] = a9;
			swap(&a[j], &a[l]);
		}
	}
}
