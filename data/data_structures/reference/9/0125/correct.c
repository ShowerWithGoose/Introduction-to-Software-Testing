#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void ssort(int node[101][4], int n, int temp[4]);
int node[101][4], n, temp[4];
int p, max, xans, yans, len;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &node[i][0], &node[i][1], &node[i][2], &node[i][3]);
	}
	ssort(node, n, temp);
	for (int i = 0; i < n; i++) {
		p = i;
		len = 1;
		for (int j = i + 1; j < n; j++) {
			if (node[p][2] == node[j][0] && node[p][3] == node[j][1]) {
				p = j;
				len++;
			}
		}
		if (len > max) {
			max = len;
			xans = node[i][0];
			yans = node[i][1];
		}
	}
	printf("%d %d %d", max, xans, yans);
	return 0;
}

void ssort(int node[101][4], int n, int temp[4]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (node[i][0] > node[j][0]) {
				for (int k = 0; k < 4; k++) {
					temp[k] = node[i][k];
				}
				for (int k = 0; k < 4; k++) {
					node[i][k] = node[j][k];
				}
				for (int k = 0; k < 4; k++) {
					node[j][k] = temp[k];
				}
			}
		}
	}
}
