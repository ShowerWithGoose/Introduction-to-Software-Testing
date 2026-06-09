#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N, del, map[1000], dex = 0;

struct Node
{
	int num;
	int has;
	struct Node* next;
};

struct Node* n[1000];

void init(int num)
{
	for (int i = 0; i < num; i++)
	{
		n[i] = (struct Node*)malloc(sizeof(struct Node));
		n[i]->num = i;
		n[i]->next = NULL;
		n[i]->has = 0;
		map[i] = -1;
	}
}

void add(int a1, int a2)
{
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	n2->num = a2;
	n2->next = NULL;
	n2->has = 0;
	if (n[a1]->has == 0)
	{
		n[a1]->next = n2;
		n[a1]->has = 1;
	}
	else
	{
		struct Node* last = n[a1];
		struct Node* lit = n[a1]->next;
		while (1)
		{
			if (lit->has == 0 || lit->num > a2)
			{
				break;
			}
			last = last->next;
			lit = lit->next;
		}
		if (lit->num < a2)
		{
			lit->next = n2;
			lit->has = 1;
		}
		else
		{
			last->next = n2;
			n2->next = lit;
			n2->has = 1;
		}
	}
}

void input()
{
	int m, a1, a2;
	scanf("%d %d", &N, &m);
	init(N);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a1, &a2);
		add(a1, a2);
		add(a2, a1);
	}
	scanf("%d", &del);
}

void reset()
{
	memset(map, -1, 1000 * sizeof(int));
	dex = 0;
	printf("\n");
}

int search(int d)
{
	for (int i = 0; i < dex; i++)
		if (map[i] == d)
			return 1;
	return 0;
}

void dfs(int d, struct Node* node)
{
	if (search(node->num))
		return;
	map[dex++] = node->num;
	printf("%d ", node->num);
	struct Node* lit = node;
	for (int i = 0; i < N; i++)
	{
		if (lit->has == 1)
		{
			lit = lit->next;
		}
		else
		{
			break;
		}
		if (lit->num != d && lit->num != node->num && !search(lit->num))
		{
			dfs(d, n[lit->num]);
		}
	}
}

void bfs(int d)
{
	map[dex++] = 0;
	int i = 0;
	while (map[i] != -1)
	{
		struct Node* n2 = n[map[i]];
		while (n2->has == 1)
		{
			n2 = n2->next;
			if (n2->num == d)
			{
				continue;
			}
			if (!search(n2->num))
			{
				map[dex++] = n2->num;
			}
		}
		i++;
	}
	for (i = 0; i < dex; i++)
	{
		printf("%d ", map[i]);
	}
}

int main()
{
	input();
	dfs(-1, n[0]);
	reset();
	bfs(-1);
	reset();
	dfs(del, n[0]);
	reset();
	bfs(del);
	return 0;
}

