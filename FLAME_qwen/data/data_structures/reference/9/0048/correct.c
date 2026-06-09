#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000000

struct Line
{
	int start[2];
	int finish[2];
} line[MAXSIZE];

int record[MAXSIZE];

int main()
{
	int n, i, j, leftx, lefty, rightx, righty, temp, max = 0, ansx, ansy;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf ("%d%d%d%d", &line[i].start[0], &line[i].start[1], &line[i].finish[0], &line[i].finish[1]);
	}
	for (i = 0; i < n; i++)
	{
		if (record[i] != 0)
		{
			continue;
		}
		record[i] = -1;
		temp = 1;
		leftx = line[i].start[0];
		lefty = line[i].start[1];
		rightx = line[i].finish[0];
		righty = line[i].finish[1];
		int flag = 1;
		while (flag == 1)
		{
			flag = 0;
			for (j = i + 1; j < n; j++)
			{
				if (record[j] != 0)
				{
					continue;
				}
				else if (leftx == line[j].finish[0] && lefty == line[j].finish[1])
				{
					leftx = line[j].start[0];
					lefty = line[j].start[1];
					temp++;
					record[j] = -1;
					flag = 1;
				}
				else if (rightx == line[j].start[0] && righty == line[j].start[1])
				{
					rightx = line[j].finish[0];
					righty = line[j].finish[1];
					temp++;
					record[j] = -1;
					flag = 1;
				}
			}
		}
		if (temp > max)
		{
			max = temp;
			ansx = leftx;
			ansy = lefty;
		}
	}
	printf ("%d %d %d", max, ansx, ansy);
	return 0; 
}




