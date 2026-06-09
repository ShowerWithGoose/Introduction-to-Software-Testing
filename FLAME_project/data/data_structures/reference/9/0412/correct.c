#include <stdio.h>

// #define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#pragma warning(disable: 4996)
#endif

#define MAX_NUM 105

typedef struct tagPoint
{
	int x;
	int y;
} Point;

typedef struct tagSegment
{
	Point start;
	Point end;
	struct tagSegment* father;
	int size;
} Segment;

// point operations
int point_compare(const Point* p1, const Point* p2);
void point_get(Point* point);
void point_print(Point* point);

// segment operations
int segment_compare(const Segment* s1, const Segment* s2);
int segment_match(const Segment* s1, const Segment* s2);
void segment_init(Segment* segment);
void segment_get(Segment* segment);
void segment_print(Segment* segment);

// union find set operations
Segment* get_father(Segment* segment);
int find(Segment* s1, Segment* s2);
int merge(Segment* s1, Segment* s2);

// top operations
void handle();
int readin(Segment* dest);

int main()
{
#ifdef ENABLE_DEBUG
	freopen("in.txt", "r", stdin);
#endif

	handle();

#ifdef ENABLE_DEBUG
	fclose(stdin);
#endif

	return 0;
}

// point operations
int point_compare(const Point* p1, const Point* p2)
{
	if (p1->x == p2->x)
		return p1->y - p2->y;
	else
		return p1->x - p2->x;
}

void point_get(Point* point)
{
	scanf("%d %d", &point->x, &point->y);
}

void point_print(Point* point)
{
	printf("%d %d", point->x, point->y);
}

// segment operations
int segment_compare(const Segment* s1, const Segment* s2)
{
	return point_compare(&s1->start, &s2->start);
}

int segment_match(const Segment* s1, const Segment* s2)
{
	return (point_compare(&s1->start, &s2->start) == 0) \
		|| (point_compare(&s1->start, &s2->end) == 0) \
		|| (point_compare(&s1->end, &s2->start) == 0) \
		|| (point_compare(&s1->end, &s2->end) == 0);
}

void segment_init(Segment* segment)
{
	segment->father = segment;
	segment->size = 1;
}

void segment_get(Segment* segment)
{
	segment_init(segment);

	point_get(&segment->start);
	point_get(&segment->end);
}

void segment_print(Segment* segment)
{
#ifdef ENABLE_DEBUG
	printf("%p\t %p\t %2d\t> ", segment, segment->father, segment->size);
	point_print(&segment->start);
	putchar(' ');
	point_print(&segment->end);
	putchar('\n');
#else
	printf("%d ", segment->size);
	point_print(&segment->start);
	putchar('\n');
#endif
}

// union find set operations
Segment* get_father(Segment* segment)
{
	if (segment->father == segment)
		return segment;
	else
		return segment->father = get_father(segment->father);
}

int find(Segment* s1, Segment* s2)
{
	return get_father(s1) == get_father(s2);
}

int merge(Segment* s1, Segment* s2)
{
	Segment* f1 = get_father(s1);
	Segment* f2 = get_father(s2);

	if (f1 == f2)
		return 0;

	if (f1->size > f2->size)
	{
		f2->father = f1;
		f1->size += f2->size;
	}
	else
	{
		f1->father = f2;
		f2->size += f1->size;
	}

	return 1;
}

// top operations
void handle()
{
	Segment segment_list[MAX_NUM];
	Segment* root;
	Segment* start;

	int num = readin(segment_list);

	// merge connected segments
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (segment_match(&segment_list[i], &segment_list[j]))
				merge(&segment_list[i], &segment_list[j]);
		}
	}

	// find the longest segment set
	root = segment_list;
	for (int i = 1; i < num; i++)
	{
		if (segment_list[i].size > root->size)
			root = &segment_list[i];
	}

#ifdef ENABLE_DEBUG
	for (int i = 0; i < num; i++)
		segment_print(&segment_list[i]);
	putchar('\n');
#endif

	// find the start of the segment set
	start = root;
	for (int i = 0; i < num; i++)
	{
		if (segment_list[i].father != root)
			continue;

		if (segment_compare(&segment_list[i], start) < 0)
			start = &segment_list[i];
	}

	// print the start.
	start->size = root->size;
	segment_print(start);
}

int readin(Segment* dest)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		segment_get(dest + i);

	return n;
}

