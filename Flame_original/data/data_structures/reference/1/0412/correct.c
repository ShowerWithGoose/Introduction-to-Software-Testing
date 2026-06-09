#include <stdio.h>

void swap(int* a, int* b);
int next_permutation(int* begin, int* end);
int main()
{
	int array[15];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		array[i] = i + 1;


	do
	{
		for (int i = 0; i < n; ++i)
			printf("%d ", array[i]);
		putchar('\n');
	} while (next_permutation(array, array + n));

	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	
	*a = *b;
	*b = temp;
}

int next_permutation(int* begin, int* end)
{
	int* it;
	int* it2;
	int* it3;
	int* flag;
	
	for (it = end - 1; it > begin; it--)
	{
		/*
		** Find the last inverted pair.
		*/
		if (*(it - 1) < *it)
		{
			flag = it;
			/*
			** Find the minimum one which is greater than
			** *(it - 1)
			*/
			for (it2 = it + 1; it2 < end; it2++)
			{
				if (*it2 > *(it - 1))
					flag = it2;
				else
					break;
			}
			
			/*
			** Swap to make next one to be the front.
			** And then reverse the rest of the array.
			*/
			swap(it - 1, flag);
			for (it2 = it, it3 = end - 1; it2 < it3; it2++, it3--)
				swap(it2, it3);
				
			return 1;
		}
	}
	
	return 0;
}



