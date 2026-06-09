#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Line
{
	Point head;
	Point tail;
}Line;

void scanLine(Line* line) {
	scanf("%d%d%d%d", &(line->head.x), &(line->head.y), &(line->tail.x), &(line->tail.y));
}

void quickSortLine(Line** a, int n)
{
	int* stack = (int*)malloc(2 * n * sizeof(int));
	int p = 0;
	int beg, end;
	int l, r;
	Line* base, * hold;
	stack[p++] = 0;
	stack[p++] = n - 1;
	int i;
	while (p)
	{
		end = stack[--p];
		beg = stack[--p];
		l = beg;
		r = end;
		base = a[l + (r - l) / 2];
		while (l <= r)
		{
			while (a[l]->head.x < base->head.x) l++;//如果l刚刚拿了个<=base的数，由于r止步于<=base的数，所以总能保证最后r - l == 1
			while (a[r]->head.x > base->head.x) r--;
			if (l <= r)
			{
				hold = a[l];//其实等于时不必交换，但为了便于书写，与l<r情况并在一起
				a[l] = a[r];
				a[r] = hold;
				l++;
				r--;
			}
		}
		if (l < end)
		{
			stack[p++] = l;
			stack[p++] = end;
		}
		if (r > beg)
		{
			stack[p++] = beg;
			stack[p++] = r;
		}
	}
}

int isEqual(Point head, Point tail) {
	if (head.x == tail.x && head.y == tail.y) return 1;
	return 0;
}

typedef struct Node
{
	int cnt;
	Point head;
	Point tail;
	struct Node* next;
}Node;

int main() {
	int n;
	scanf("%d", &n);
	Line** a = (Line**)malloc(n * sizeof(Line*));
	int i;
	for (i = 0; i < n; i++) {
		a[i] = (Line*)malloc(sizeof(Line));
		a[i]->head.x = 0;
		scanLine(a[i]);
	}

	//排序
	quickSortLine(a, n);

	//存储数据
	Node* head = NULL, * tail = NULL, * curr;
	for (i = 0; i < n; i++) {
		curr = head;
		while (curr) {
			if (isEqual(curr->tail, a[i]->head)) {
				curr->tail.x = a[i]->tail.x;
				curr->tail.y = a[i]->tail.y;
				curr->cnt++;
				break;
			}
			curr = curr->next;
		}
		if (!head)
			head = tail = (Node*)malloc(sizeof(Node));
		else
			tail = tail->next = (Node*)malloc(sizeof(Node));
		tail->cnt = 1;
		tail->head.x = a[i]->head.x;
		tail->head.y = a[i]->head.y;
		tail->tail.x = a[i]->tail.x;
		tail->tail.y = a[i]->tail.y;
		tail->next = NULL;
	}

	Node* max = (Node*)malloc(sizeof(Node));
	curr = head;
	while (curr) {
		if (max->cnt < curr->cnt)
			max = curr;
		curr = curr->next;
	}

	printf("%d %d %d", max->cnt, max->head.x, max->head.y);

	return 0;
}
