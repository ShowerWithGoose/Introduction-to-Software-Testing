#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
struct duan{
	int x1;
	int y1;
	int x2;
	int y2;
}line[105];
int search(int);
int num = 0, n;
int main()
{
	int  i, max = -1, mi;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
	}
	for (i = 0; i < n; i++)
	{
		num = 0;
		search(i);
		if (num > max)
		{
			mi = i;
			max = num;
		}
		
	}
	printf("%d %d %d", max+1, line[mi].x1, line[mi].y1);
	return 0;
}
int search(int i)
{
	int j;
	for (j = 0; j < n; j++)//不应该这样 跳出循环了 
	{
		if ((line[i].x2 == line[j].x1)&&(line[i].y2 == line[j].y1)&&j != i)//无论如何都找不到的情况 
		{
			num++;
			search(j);
			break;
		}
	}
	if (j == n)
	return -1;
	return num;
} 

