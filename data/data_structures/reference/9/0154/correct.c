#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//连续线段
//思路：先用qsort根据每条线段的左端点的横坐标排序，从第一个端点开始遍历，用二分查找在后面的端点中找到匹配的断点，形成递归，终点是无法找到下一个点，对于
//已经用过的点用flag标记不会再用，遍历的结束条件是所有点都被标记过了
typedef struct line {
		int x1;
		int y1;
		int x2;
		int y2;
	}line;
typedef struct node {
	int x;
	int y;
}nd;
int flag[101];
int compare(const void* a, const void* b)
{
	line* pa = (line*)a;
	line* pb = (line*)b;
	return pa->x1-pb->x1;
}
int bsearch(line ln[], int i)
{
	int tflag = 0;
	int ori = i;
	while (ln[ori].x2 != ln[i + 1].x1 && ln[ori].y2 != ln[i + 1].y1)
	{
		i++;
		if (i == 100)
		{
			tflag = 1;
			break;
		}
	}
	if (!tflag)
		return i + 1;
	else return -1;
};//根据ln[i]的x2
//找到了返回该点的序号，找不到返回-1
int path(line ln[], int i,int nodenum,nd start[])
{
	flag[i] = 1;
	if (bsearch(ln, i) > -1)
	{
		nodenum++;
		path(ln, bsearch(ln, i), nodenum, start);
	}
	else return nodenum;
}//path实现的功能：找到一条路径，然后将长度和起点作为返回值存储下来，起点用一个结构体数组存，长度是结构体数组的序号
//nodenum表示当前路径中有几个点，当找不到的时候把数据存进去
int main()
{
	int num = 0;
	scanf("%d", &num);
	line ln[105];

	for (int i = 0; i < num; i++)
		scanf("%d%d%d%d", &ln[i].x1, &ln[i].y1, &ln[i].x2, &ln[i].y2);
	qsort(ln, num, sizeof(line), compare);//根据左端点横坐标排序
	nd start[101] = {0};
	//如果有问题的话，把0换成很小的数或很大的数
	for (int i = 0; i < num; i++)
		if (!flag[i])
		{
			start[path(ln, i, 1, start)].x = ln[i].x1;
			start[path(ln, i, 1, start)].y = ln[i].y1;
		}
	for (int i = 100; i > 1; i--)
		if (start[i].x)
		{
			printf("%d %d %d", i, start[i].x, start[i].y);
			break;
		}
	return 0;
}

