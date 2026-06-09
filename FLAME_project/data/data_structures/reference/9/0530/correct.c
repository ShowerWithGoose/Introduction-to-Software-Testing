//思想是每个线段总有一个开头，先把那个开头找出来，把所有具有这个特征的放进一个数组，然后不断从头连接他后边可以连接的线段
#include <stdio.h>
typedef struct node {
	int start[3];
	int end[3];
	int number;
}line;
line save[100] = { 0 }, whole[100] = { 0 };
int nbw = 0,n;
void handle(line save[], line whole[]);
void tie(line save[], line whole[]);

int main()
{
	int i,max=0,pri[3]={0};
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &save[i].start[0], &save[i].start[1], &save[i].end[0], &save[i].end[1]);
		save[i].number = 1;
	}
	handle(save, whole);
	tie(save, whole);
	for (i = 0; i < nbw; i++)
	{
		if (max < whole[i].number)//对各个连完的线段进行比较
		{
			max = whole[i].number;
			pri[0] = whole[i].start[0];
			pri[1] = whole[i].start[1];
		}
	}
	printf("%d %d %d", max, pri[0], pri[1]);
	return 0;
}

void handle(line save[], line whole[])
{
	int i=0,j=0,flag = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == i)//排除自身
				continue;
			else
			{
				if (save[i].start[0] == save[j].end[0] && save[i].start[1] == save[j].end[1])
				{
					flag = 1;//因为我们要检测这个线段是不是最左边那个起始线段，起始线段具有特征左边不连东西，所以左边可以作为监测点
					break;//这个线段将来肯定要连上，所以直接跳出循环
				}
			}
		}
		if (flag == 0)//如果没有可以相连的，那么这个就是最左边的线段
		{
			whole[nbw] = save[i];//“起始线段”数组
			nbw++;//记录共有多少条起始线段
		}
		flag = 0;
	}

}
void tie(line save[], line whole[])
{
	int i, j;
	for (i = 0; i < nbw; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (whole[i].end[0] == save[j].start[0] && whole[i].end[1] == save[j].start[1])
			{//显然到自身的时候是肯定满足不了这个判断条件的，所以可以不用管
				whole[i].number++;
				whole[i].end[0] = save[j].end[0];//更新线段
				whole[i].end[1] = save[j].end[1];
				j = -1;//因为可能有输入顺序是（1，1）（2，2）；（3，3）（4，4）；（2，2）（3，3）；
				      //的情况，所以没连接一条都要从头开始重新检测，因为连接完毕的端点已经更新，所以不用担心死循环
			}
		}
	}
}
