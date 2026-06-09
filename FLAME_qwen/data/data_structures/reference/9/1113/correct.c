#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct location{
	int x1;
	int y1;
	int x2;
	int y2;
	
} LINK;
LINK line[100];
int rec[105];
int flag[105];
void search(LINK a[],int n,int depth,LINK b,int number) {
	for (int i = 0; i < n; i++) {
		if (flag[i] == 0 &&b.x2==a[i].x1&&b.y2==a[i].y1) {
			flag[i] = 1;
			search(a, n, depth + 1, a[i],number);
			flag[i] = 0;
		}
	}
	rec[number] = depth >= rec[number] ? depth : rec[number];

}
int main()
{
	int n;
	int cnt=0;
	scanf("%d", &n);//∂¡»În∏ˆœﬂ∂Œ
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &(line[i].x1), &(line[i].y1), &(line[i].x2),&(line[i].y2));
	}
	for (int i = 0; i < n; i++) {
		flag[i] = 1;
		search(line, n, 1, line[i], i);
		flag[i] = 0;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (rec[max] <= rec[i]) max = i;
	}
	printf("%d %d %d", rec[max], line[max].x1, line[max].y1);
	return 0;
}
