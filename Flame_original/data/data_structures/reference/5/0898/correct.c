#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
int s_rank(const void* p1, const void* p2)
{
	return ((int*)p2)[1] - ((int*)p1)[1]; //第一列元素比较((int*)b)[2]
}
int m, count;
int flag = 0;
int num = 0;
int sum = 0;
int arr[5000][2];
typedef struct nod 
{
	int a;
	int x;
	struct nod* link;
}node,*nodee;
int n;
int main()
{
	memset(arr, -1, sizeof(arr));
	nodee first= NULL, p=NULL, q=NULL;
	int i = 0;
	while(1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		num++;
		q = (nodee)malloc(sizeof(node));
		q->a = a;
		q->x = b;
		q->link = NULL;
		if (first == NULL)
		{
			first = p = q;
		}
		else
		{
			p->link = q;
		}
		p = q;
		p->link = first;
		if (getchar() == '\n')
			break;
	}
	nodee first1 = NULL, p1 = NULL, q1 = NULL;
	int i1 = 0;
	while (1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		sum++;
		q1 = (nodee)malloc(sizeof(node));
		q1->a = a;
		q1->x = b;
		q1->link = NULL;
		if (first1 == NULL)
		{
			first1 = p1 = q1;
		}
		else
		{
			p1->link = q1;
		}
		p1 = q1;
		p1->link = first1;
		if (getchar() == '\n')
			break;
	}
	nodee p2=first, q2=first1;
	for (int j = 1;j <= num;j++)
	{
		for (int i = 1;i <= sum;i++)
		{
			int d = p2->a * q2->a;
			int c = p2->x + q2->x;
			for (int z = 0;z < count;z++)
			{
				if (arr[z][1] == c)
				{
					arr[z][0] += d;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				arr[count][0] = d;
				arr[count][1] = c;
				count++;
			}
			flag = 0;
			q2 = q2->link;
		}
		p2 = p2->link;
	}
	qsort(arr, count, 8, s_rank);
	for (int i = 0;i < count;i++)
		printf("%d %d ", arr[i][0], arr[i][1]);
	return 0;
}


