#include <stdio.h>

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	point point[2];
	int n;
} Line;

int judge(point a, point b) {
	if (a.x == b.x && a.y == b.y)
		return 1;
	else
		return -1;
}

int JUDGE(point a, Line b) {
	if (judge(a, b.point[0]) == 1)
		return 1;
	else if (judge(a, b.point[1]) == 1)
		return 1;
	else
		return -1;

}

int main(void) {
	int N;
	scanf("%d", &N);

	Line line[105];
	for (int i = 0; i <= 104; i++) {
		line[i].n = -1;
		line[i].point[0].x = line[i].point[1].y = 0;
	}

	point a, b;
	int lineN = 0;
	int flag = 0;
	for (int i = 1; i <= N; i++) {

		flag = 0;
		scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);

		int t = -1;

		for (int j = 1; j <= lineN; j++) {
			if ( line[j].n != -1 && (JUDGE(a, line[j]) == 1 || JUDGE(b, line[j]) == 1) && flag == 0)   {
				line[j].n++;
				if (JUDGE(a, line[j]) == 1 ) { // a
					line[j].point[1] = b;
				} else {	//b
					line[j].point[0] = a;
				}
				flag = 1;
				t = j;
			} else if (line[j].n != -1 && (JUDGE(a, line[j]) == 1 || JUDGE(b, line[j]) == 1) && flag == 1) {
				if ( line[t].point[0].x >= line[j].point[1].x ) {
					line[t].n = line[t].n  + line[j].n;
					line[t].point[0] = line[j].point[0];
				} else {
					line[t].n = line[t].n  + line[j].n;
					line[t].point[1] = line[j].point[1];
				}
				flag = 2;
				line[j].n = -1;
			}
		}
		if (flag == 0) {
			line[++lineN].n = 1;
			line[lineN].point[0] = a;
			line[lineN].point[1] = b;
		}
	}

	int max = -1;
	point l, r;

	for (int i = 1; i <= lineN; i++) {
		if (line[i].n > max) {
			max = line[i].n;
			l = line[i].point[0];
			r = line[i].point[1];
		}
	}

	printf("%d %d %d", max, l.x, l.y);
//	printf("\n%d %d", r.x, r.y);
//	printf("\n%d", lineN);

	return 0;
}
//4
//3 1 4 2
//1 1 2 2
//2 2 3 1
//4 2 5 1
//
//3 2 2
//2 2
//3

