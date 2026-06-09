#include<stdio.h>
struct point {
	int x;
	int y;
};
typedef struct hyb1 {
	struct point point1, point2;
	int len;
} Line1;
Line1 line[100];
Line1 hyb;
int check(int i, int j);
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &line[i].point1.x, &line[i].point1.y, &line[i].point2.x, &line[i].point2.y);
	}
	for (int i = 0; i < k; i++) {
		if (line[i].point1.x > line[i].point2.x) {
			hyb.point2 = line[i].point1;
			line[i].point1 = line[i].point2;
			line[i].point2 = hyb.point2;
		}	
	}
	//========================= ‰»Î
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (check(i, j) == 1) {
				line[i].point1 = line[i].point1;
				line[i].point2 = line[j].point2;
				if (line[i].point1.x > line[i].point2.x) {
					line[j].point2 = line[i].point1;
					line[i].point1 = line[i].point2;
					line[i].point2 = line[j].point2;
				}
				for (int l = j; l < k - 1; l++) {
					line[l] = line[l + 1];
				}
				k--;
				line[i].len++;
				i --;
				break;
			} else if (check(i, j) == -1) {
				line[i].point1 = line[i].point2;
				line[i].point2 = line[j].point1;
				if (line[i].point1.x > line[i].point2.x) {
					line[j].point2 = line[i].point1;
					line[i].point1 = line[i].point2;
					line[i].point2 = line[j].point2;
				}
				for (int l = j; l < k - 1; l++) {
					line[l] = line[l + 1];
				}

				k--;
				line[i].len++;
				i --;
				break;
			}
		}
	}
	int loc = 0, max = 0;
	for (int i = 0; i < k; i++) {
		if (line[i].len > max) {
			max = line[i].len;
			loc = i;
		}
	}
	if (line[loc].point1.x < line[loc].point2.x)printf("%d %d %d", line[loc].len + 1, line[loc].point1.x, line[loc].point1.y);
	else printf("%d %d %d", line[loc].len + 1, line[loc].point2.x, line[loc].point2.y);
	return 0;
}
int check(int i, int j) {
	if (line[i].point2.x == line[j].point1.x && line[i].point2.y == line[j].point1.y)return 1;
	if (line[i].point1.x == line[j].point2.x && line[i].point1.y == line[j].point2.y)return -1;
	return 0;
}



