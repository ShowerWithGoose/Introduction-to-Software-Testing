#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int i = 0;
	int flag = 0;
	int zhan[101];
	int judge,path,alert;
	scanf("%d %d", &judge, &zhan[0]);
	alert = judge;
	while (scanf("%d ", &judge)==1) {
		if (judge != 0 && judge != 1 && judge != -1) {
			if (i == -1) {
				i++;
			}
			zhan[i] = judge;
			alert = path;
			continue;
		}
		if (judge == -1) {
			break;
		}
		switch (judge) {
		case(1):
			if (flag == 0) {
				scanf("%d ", &path);
			}
			if (alert != 0||i==-1) {
				i++;
			}
			if (i <=100) {
				zhan[i] = path;
			}
			else { printf("error "); }
			break;
		case(0):
			if (alert == 0&&i>-1)i--;
			if (i > -1) {
				printf("%d ", zhan[i]);
			}
			else { printf("error "); }
			scanf("%d", &path);
			alert = judge;
			while (path == 0 ) {
				if (alert == 0&&i>=0)i--;
				if (i > -1) {
					printf("%d ", zhan[i]);
				}
				else { printf("error "); }
				alert = path;
				scanf("%d", &path);
			}
			break;
		default: break;
		}

	}
	return 0;
}
