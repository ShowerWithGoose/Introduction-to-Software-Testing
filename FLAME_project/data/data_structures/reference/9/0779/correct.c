#pragma warning(disable:4996)
#include<stdio.h>

struct line 
{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
	struct line* link;
};

int main() 
{
	struct line LINE[100];
	struct line* p;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &LINE[i].x1, &LINE[i].y1, &LINE[i].x2, &LINE[i].y2);
		LINE[i].link = NULL;
		LINE[i].len = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (LINE[i].x1 == LINE[j].x2 && LINE[i].y1 == LINE[j].y2)
				LINE[j].link = &LINE[i];
		}
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (p = &LINE[i]; p != NULL; p = p->link)
			s++;
		LINE[i].len = s;
	}
	int max=0, order=0;
	for (int i = 0; i < n; i++) {
		if (LINE[i].len > max) {
			max = LINE[i].len;
			order = i;
		}
	}
	printf("%d %d %d\n", max, LINE[order].x1, LINE[order].y1);
	return 0;
}
