#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct LINE {
	int leftx;
	int lefty;
	int rightx;
	int righty;
	int count;
};
struct LINE lines[105];//创建线段数组
int judge(struct LINE *a, struct LINE *b)//比较a,b线段是否连续
{
	if (b->rightx == a->leftx && b->righty == a->lefty)
	{
		a->leftx = b->leftx;
		a->lefty = b->lefty;
		a->count=a->count+b->count;
		return 1;
	}
	else if (b->leftx == a->rightx && b->lefty == a->righty)
	{
		a->rightx = b->rightx;
		a->righty = b->righty;
		a->count=a->count+b->count;
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n;
	int i,I,j,k;
	int op;
	scanf("%d\n", &n);//读入线段条数
	for (i = 0; i < n; i++)
		lines[i].count = 1;//count置1
	scanf("%d%d%d%d\n", &lines[0].leftx,&lines[0].lefty,&lines[0].rightx,&lines[0].righty);
	for (I = 1,i=1; I < n; I++,i++)
	{
		scanf("%d%d%d%d\n", &lines[i].leftx, &lines[i].lefty, &lines[i].rightx, &lines[i].righty);
		for (j = 0; j < i; j++)
		{
			op = judge(&lines[j], &lines[i]);
			if (op == 1)
			{
				for (k = 0; k < i; k++)
				{
					if(j!=k)
						judge(&lines[j], &lines[k]);
				}					
				break;
			}
		}
		if (op == 1)
			i--;
	}//此时已经得到线段数量与左起点

	int maxcount=lines[0].count, maxi=0;
	for (i = 1; i < n; i++)
	{
		if (maxcount < lines[i].count)
		{
			maxcount = lines[i].count;
			maxi = i;
		}
	}
	printf("%d %d %d\n", maxcount, lines[maxi].leftx, lines[maxi].lefty);
	return 0;
}


