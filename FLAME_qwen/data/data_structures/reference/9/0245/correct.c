#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *, const void *);
void func();
int search(int);

int max_length;
int max_x, max_y;
int count;
int arr[114];

typedef struct {
	int start_x, start_y, end_x, end_y;
}_lines;

_lines lines[114];

int main()
{
	int i;
	scanf("%d", &count);
	for(i = 0; i < count; i++)
		scanf("%d %d %d %d",&lines[i].start_x, &lines[i].start_y, &lines[i].end_x, &lines[i].end_y);
	qsort(lines, count, sizeof(lines[0]), cmp);
	func();
	printf("%d %d %d", max_length, max_x, max_y);
	return 0;
}

int cmp(const void *a, const void *b)
{
	if((*(_lines *)a).start_x > (*(_lines *)b).start_x)
		return 1;
	else if((*(_lines *)a).start_x < (*(_lines *)b).start_x)
		return -1;
	else
	{
		if((*(_lines *)a).end_x > (*(_lines *)b).end_x)
			return 1;
		else if((*(_lines *)a).end_x < (*(_lines *)b).end_x)
			return -1;
	}
}

void func()
{
	int i, j = 0, x, y, temp = 1, p, flag = 0;
	for(i = 0; i < count ; i++)
	{
		x = lines[i].end_x;
		y = lines[i].end_y;
		while(1)
		{
			p = search(x);
			if(p == -1)
				break;
			for(j = 0; j < p; j++)
			{
				if(lines[arr[j]].start_y == y)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				x = lines[arr[j]].end_x;
				y = lines[arr[j]].end_y;
				temp++;
				flag = 0;
			}
			else
				break;
		}
		if(temp > max_length)
		{
			max_length = temp;
			max_x = lines[i].start_x;
			max_y = lines[i].start_y;
		}
		temp = 1;
	}
}

int search(int key)
{
	int i, j = 0;
	memset(arr, 0, sizeof(int));
	for(i = 0; i < count; i++)
	{
		if(lines[i].start_x == key)
			arr[j++] = i;
	}
	if(j != 0)
		return j;
	return -1;
}


