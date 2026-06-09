#pragma warning(disable : 4996)
#include <stdio.h>

struct line {
	int start_point_x;
	int start_point_y;
	int end_point_x;
	int end_point_y;
	int num;
} line[100 + 1];

int get_coor[100 + 1][4];

int main() {

	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &get_coor[i][j]);

	int k = 0;

	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (get_coor[i][0] == get_coor[j][2] && get_coor[i][1] == get_coor[j][3]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			line[k].start_point_x = get_coor[i][0];
			line[k].start_point_y = get_coor[i][1];
			line[k].end_point_x = get_coor[i][2];
			line[k].end_point_y = get_coor[i][3];
			k++;
		}
	}

	for (int i = 0; i < n; i++) {
		line[i].num = 0;
		for (int j = 0; j < n; j++) {
			if (line[i].end_point_x == get_coor[j][0] && line[i].end_point_y == get_coor[j][1]) {
				line[i].end_point_x = get_coor[j][2];
				line[i].end_point_y = get_coor[j][3];
				line[i].num++;
				j = -1;
			}
		}
	}

	int max = 1;
	int sym = 0;

	for (int i = 0; i < n; i++) {
		if (line[i].num > max) {
			max = line[i].num;
			sym = i;
		}
	}

	printf("%d %d %d", line[sym].num + 1, line[sym].start_point_x, line[sym].start_point_y);

}


