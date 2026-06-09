#include <stdio.h>
#include <string.h>

int first[100000];
int last[100000];

void array (int step, int N)
{
	int i;
	if (step == N)
	{
		int i;
		for (i = 0; i < N - 1; i++)
		{
			printf ("%d ", last[i]);
		}
		printf ("%d", last[i]);
		printf ("\n");
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			if (!first[i])
			{
				first[i] = 1;
				last[step] = i + 1;
				array(step + 1, N);
				first[i] = 0;
			}
		}
	}
} 

int main()
{
	int n;
	scanf ("%d", &n);
	array(0, n);
	return 0;
}




