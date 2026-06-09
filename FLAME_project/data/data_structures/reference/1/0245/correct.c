#include <stdio.h>

int num[1145][14], num_sort[1145];
int n, l = 1;

void AllRange(int, int);
void exchange(int, int);
void sort();
void print();

int fact(int);
int pow10(int);
int cmpfunc(const void*, const void*);

int main()
{
    scanf("%d", &n);
    int i;
	for(i = 0; i < n; i++)
	    num[0][i] = i + 1;
    AllRange(0, n - 1);
    sort();
    qsort(num_sort, fact(n) + 1, sizeof(int), cmpfunc);
	print();
    return 0;
}

void AllRange(int a, int b)
{
    int i;
    if(a == b)
    {
        for(i = 0; i < n; i++)
            num[l][i] = num[0][i];
        l++;
    }
    else
    {
        for(i = a; i <= b; i++)
        {
            exchange(i, a);
            AllRange(a + 1, b);
            exchange(a, i);
        }
    }
}

void exchange(int a, int b)
{
    int temp;
    temp = num[0][a];
    num[0][a] = num[0][b];
    num[0][b] = temp;
}

void sort()
{
	int i, j;
	for(i = 1; i <= fact(n); i++)
	{
		for(j = 0; j < n; j++)
			num_sort[i] += num[i][j] * pow10(j);
	}
}
void print()
{
	int i, j, k, temp;
	for(i = 1; i <= fact(n); i++)
	{
		k = n - 1;
		while(num_sort[i] > 0)
		{
			temp = num_sort[i] / pow10(k);
			printf("%d ", temp);
			num_sort[i] %= pow10(k);
			k--;
		}
		printf("\n");
	}
}

int fact(int n)
{
	if(n > 1)
		return n*fact(n - 1);
	return 1;
}

int pow10(int n)
{
	if(n >= 1)
		return 10*pow10(n - 1);
	return 1;
}

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}



