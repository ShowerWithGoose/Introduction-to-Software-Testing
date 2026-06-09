#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Line
{
	Point point1;
	Point point2;
}Line;

void scanLine(Line* line) {
	scanf("%d%d%d%d", &(line->point1.x), &(line->point1.y), &(line->point2.x), &(line->point2.y));
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
			while (a[l]->point1.x < base->point1.x) l++;//如果l刚刚拿了个<=base的数，由于r止步于<=base的数，所以总能保证最后r - l == 1
			while (a[r]->point1.x > base->point1.x) r--;
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

int isEqual(Point point1, Point point2) {
	if (point1.x == point2.x && point1.y == point2.y) return 1;
	return 0;
}

typedef struct Node
{
	int count;
	Point head;
	Point tail;
	struct Node* next;
}Node;

int main() {
	int n;
	scanf("%d", &n);
	Line** lines = (Line**)malloc(n * sizeof(Line*));
	int i;
	for (i = 0; i < n; i++) {
		lines[i] = (Line*)malloc(sizeof(Line));
		lines[i]->point1.x = 0;
		scanLine(lines[i]);
	}

	//排序
	quickSortLine(lines, n);

	//存储数据
	Node* head = NULL, * tail = NULL, * curr;
	for (i = 0; i < n; i++) {
		curr = head;
		while (curr) {
			if (isEqual(curr->tail, lines[i]->point1)) {
				curr->tail.x = lines[i]->point2.x;
				curr->tail.y = lines[i]->point2.y;
				curr->count++;
				break;
			}
			curr = curr->next;
		}
		if (!head)
			head = tail = (Node*)malloc(sizeof(Node));
		else
			tail = tail->next = (Node*)malloc(sizeof(Node));
		tail->count = 1;
		tail->head.x = lines[i]->point1.x;
		tail->head.y = lines[i]->point1.y;
		tail->tail.x = lines[i]->point2.x;
		tail->tail.y = lines[i]->point2.y;
		tail->next = NULL;
	}

	Node* max = (Node*)malloc(sizeof(Node));
	curr = head;
	while (curr) {
		if (max->count < curr->count)
			max = curr;
		curr = curr->next;
	}

	printf("%d %d %d", max->count, max->head.x, max->head.y);

	return 0;
}
