#include <stdio.h>
#include <stdlib.h>

struct jg{
	int x1, x2, y1, y2;
	int cnt;
}points[110];

int cmp(const void * p, const void * q) {
	struct jg * pp = (struct jg *) p;
	struct jg * qq = (struct jg *) q;
	return pp->x1 - qq->x1;
}

int main() {
	      
	int N, max = 0, p;		
	scanf("%d", &N);
	
	for (int i = 0; i < N; i ++)
		scanf("%d%d%d%d", &points[i].x1, &points[i].y1, &points[i].x2, &points[i].y2);
		
	qsort(points, N, sizeof(points[0]), cmp);
	
	for (int i = 0; i < N; i++) 
		points[i].cnt = 1;
	
	for (int i = N - 1; i >= 0; i--) { 
		for (int j = i - 1; j >= 0; j--) {
			if (points[i].x1 == points[j].x2 && points[i].y1 == points[j].y2) {
				points[j].cnt += points[i].cnt;
				break;
			}
		}	
	}

	/*for (int i = 0; i < N; i ++) 
		printf("%d:%d,%d  %d,%d\n", i, points[i].x1, points[i].y1, points[i].x2, points[i].y2);
	*/
	
	for (int i = 0; i < N; i ++) {
		if (points[i].cnt > max) {
			max = points[i].cnt;
			p = i;
		}
	}
	
	printf("%d %d %d", max, points[p].x1, points[p].y1);
	
	return 0;
}


