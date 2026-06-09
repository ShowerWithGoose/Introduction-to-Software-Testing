#include<stdio.h>
#include<stdlib.h>
struct L {
	int val, top;
	struct L* next;
	struct L* front;
};

int N[2][1000][2];

int main()
{
	int a = 0, b = 0;
	do
	{
		scanf("%d %d", &N[0][a][0], &N[0][a][1]);
		a++;
	} while (getchar() != '\n');
	do
	{
		scanf("%d %d", &N[1][b][0], &N[1][b][1]);
		b++;
	} while (getchar() != '\n');
	struct L* h = (struct L*)malloc(sizeof(struct L));
	h->val = -1;
	h->top = -1;
	h->front = h;
	h->next = h;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int t = N[0][i][1] + N[1][j][1];
			if (h->next == h)
			{
				struct L* h2 = (struct L*)malloc(sizeof(struct L));
				h2->val = N[0][i][0] * N[1][j][0];
				h2->top = t;
				h2->front = h;
				h2->next = h;
				h->next = h2;
				continue;
			}
			struct L* lit = h->next;
			while (1)
			{
				if (lit->top == t)
				{
					lit->val += N[0][i][0] * N[1][j][0];
					break;
				}
				if (lit->top < t)
				{
					struct L* h2 = (struct L*)malloc(sizeof(struct L));
					h2->val = N[0][i][0] * N[1][j][0];
					h2->top = t;
					h2->front = lit->front;
					h2->next = lit;
					lit->front = h2;
					h2->front->next = h2;
					break;
				}
				if (lit->next->val == -1)
				{
					struct L* h2 = (struct L*)malloc(sizeof(struct L));
					h2->val = N[0][i][0] * N[1][j][0];
					h2->top = t;
					h2->front = lit;
					h2->next = lit->next;
					lit->next = h2;
					h2->next->front = h2;
					break;
				}
				lit = lit->next;
			}
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		h = h->next;
		if (h->val == -1)
		{
			break;
		}
		printf("%d %d ", h->val, h->top);
	}
	return 0;
}
