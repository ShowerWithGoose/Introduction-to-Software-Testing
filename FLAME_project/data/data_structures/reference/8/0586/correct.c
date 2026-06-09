#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int max_v, max_b;
int Map [100][100];
int iff[100];
int front = -1, rear = -1;
int que[100];

void gui() {
	for (int i = 0; i <= 100; i++)
		iff[i] = 0;
}

void guang(int n) {
	int i;
	rear++;
	que[rear] = n;
	printf("%d ", n);
	iff[n] = 1;
	while (rear != front) {
		front++;
		n = que[front];
		for (i = 0; i < max_v; i++) {
			if (Map[n][i] == 1)
				break;
		}
		while (i != max_v) {
			if (iff[i] == 0) {
				printf("%d ", i);
				rear++;
				que[rear] = i;
				iff[i] = 1;
			}
			for (i = i + 1; i < max_v; i++) {
				if (Map[n][i] == 1)
					break;
			}
		}
	}

}

void delay(int b) {
	int i;
	for (i = 0; i < max_v; i++) {
		if (Map[b][i] == 1) {
			Map[b][i] = 0;
			Map[i][b] = 0;
			//		iff[b] = 1;
		}
	}
}

void shen(int n) {
	int i ;
	printf("%d ", n);
	iff[n] = 1;
	for (i = 0; i < max_v; i++)
		if (Map[n][i] == 1) {
			break;
		}
	while (i != max_v) {
		if (iff[i] == 0) {
			shen(i);
		}
		for (i = i + 1; i < max_v; i++) {
			if (Map[n][i] == 1)
				break;
		}
	}


}

int main() {
	int i, h, l, dot;
	scanf("%d %d", &max_v, &max_b);
	for (i = 0; i < max_b; i++) {
		scanf("%d %d", &h, &l);
		Map[h][l] = 1;
		Map[l][h] = 1;
	}
	scanf("%d", &dot);
	shen(0);
	gui();
	printf("\n");
	guang(0);
	gui();
	printf("\n");
	delay(dot);
	shen(0);
	printf("\n");
	gui();
	guang(0);
	return 0;
}

