#include <stdio.h>

void swap(int*, int*);
void perm(int [], int, int);

int main()
{
	int n, i, array[10];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		array[i] = i + 1;
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
			perm(a, l + 1, r);
			swap(&a[j], &a[l]);
		}
	}
}
