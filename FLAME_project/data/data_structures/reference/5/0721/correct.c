#include<stdio.h>
#include<string.h>
void bubblesort(int a[], int b[], int len);
int main()
{
	int a[2][100] = {0}, b[2][100] = {0};
	int i = 0, j = 0;
	char s, s1;
	while(s != '\n')
	{
		scanf("%d %d%c", &a[0][i], &b[0][i], &s);
		i++;
	}
	while(s1 != '\n')
	{
		scanf("%d %d%c", &a[1][j], &b[1][j], &s1);
		j++;
	}
	int c[500] = {0}, d[500] = {0};
	int k = 0, l = 0, m = 0, sum;
	for(k = 0; k < i; k++)
	{
		for(l = 0; l < j; l++)
		{
			c[m] = a[0][k] * a[1][l];
			d[m] = b[0][k] + b[1][l];
			m++;
		}
	}
	for(k = 0; k < m; k++)
	{
		for(l = k + 1; l < m; l++)
		{
			if(d[k] == d[l] && d[k] != -1)
			{
				c[k] += c[l];
				d[l] = -1;
				c[l] = -1;
			}
		}
	}
	bubblesort(d, c, m);
	for(k = 0; k < m; k++)
	{
		if(c[k] != -1)printf("%d %d ", c[k], d[k]);
	}
	return 0;
}
void bubblesort(int a[], int b[], int len)
{
	int i = 0,j,temp;
	for(;i < len; i++)
		for(j = 0;j < len - i - 1; j++)
		{
			if(a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			} 
		}
}

