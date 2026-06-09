#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:6031)

struct Point
{
	int startx;
	int starty;
	int endx;
	int endy;
	int flag;
}point[101];

int startX, startY;

int isSamePoint(int x1, int y1, int x2, int y2)	//判断共点
{
	return x1 == x2 && y1 == y2;
}

int haveSamePoint1(int k, int n) //向前连接
{
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		else
		{
			if (isSamePoint(point[k].startx, point[k].starty, point[i].endx, point[i].endy))
				return i;
		}
	}
	return -1;
}
int haveSamePoint2(int k, int n) //向后连接
{
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		else
		{
			if (isSamePoint(point[k].endx, point[k].endy, point[i].startx, point[i].starty))
				return i;
		}
	}
	return -1;
}
int LINE(int k,int n)
{
	int num = 1;
	int a = haveSamePoint1(k, n);
	int b = haveSamePoint2(k, n);
	while (a != -1)
	{
		point[a].flag = 1;
		k = a;
		a = haveSamePoint1(k, n);
		num++;
	}
	startX = point[k].startx;
	startY = point[k].starty;
	while (b != -1)
	{
		point[b].flag = 1;
		k = b;
		b = haveSamePoint2(k, n);
		num++;
	}
	return num;
}

int main()
{
	int n, max = 0, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &point[i].startx, &point[i].starty, &point[i].endx, &point[i].endy);
		point[i].flag = 1;
	}
	for (int i = 0; i < n; i++)
	{
		point[i].flag = 1;
		int ans = LINE(i, n);
		if (ans > max)
		{
			x = startX;
			y = startY;
			max = ans;
		}			
	}
	printf("%d %d %d\n", max, x, y);
	return 0;
}
