#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int a[3]; int b[3];//(a[0],a[1])是起点坐标，(b[0],b[1])是终点坐标
}line;
line data[100000];
int cmp(const void *p, const void *q);
int maxline[3]; int p[3];
int main()
{
	int n, i, j, k, max = 0, count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &data[i].a[0], &data[i].a[1], &data[i].b[0], &data[i].b[1]);
	} 
	qsort(data, n, sizeof(data[0]), cmp);
	/*for (i = 0; i < n; i++)  printf("%d %d %d %d\n", data[i].a[0], data[i].a[1], data[i].b[0], data[i].b[1]);*/
	for (i = 0; i < n; i++)
	{//遍历一遍
		count = 1;//清零
		j = i; 
		p[0] = data[i].a[0]; p[1] = data[i].a[1];
		while (j < n)
		{
			k = j+1;
			while (data[k].a[0] != data[j].b[0] && data[k].a[1] != data[j].b[1] && k < n) k++;
			if (k < n)
			{//说明找到了下一个线段的起点
				count++;
			}
			j = k;
		}
		if (count > max)
		{
			max = count;
			maxline[0] = p[0]; maxline[1] = p[1];
		}
	}
	printf("%d %d %d", max, maxline[0], maxline[1]);
	return 0;
}


int cmp(const void *p, const void *q){
	line m = *(line *)p; line n = *(line *)q;
	if (m.a[0] < n.a[0])  return -1;
	else if (m.a[0] > n.a[0]) return 1;
	else{
		if (m.a[1] < n.a[1])  return -1;
		else return 1;
	}
}
