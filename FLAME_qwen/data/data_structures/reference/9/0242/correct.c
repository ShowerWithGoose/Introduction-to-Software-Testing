#include<stdio.h>
#include<stdlib.h>
int n;
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
	int num;//存线段个数
} xian[100], duan[100];
int cmp(const void *x,const void *y)
{
	return ((int *)x)[0]-((int *)y)[0];
}
int main() {
	int k = 0, mid = 0, max = 0, tem = 0;
	int xy[100][4];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &xy[i][0], &xy[i][1], &xy[i][2], &xy[i][3]);
	}
	qsort(xy,n,sizeof(xy[0]),cmp);
/*	for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",xy[i][0],xy[i][1],xy[i][2],xy[i][3]);
	}
	printf("\n");*/
	for (int i = 0; i < n; i++) { //先把空端点存上，就是未来最长的一端
		mid = 0;
		for (int j = i + 1 ; j < n; j++) {
			if ((xy[i][0] == xy[j][2]) && (xy[i][1] == xy[j][3])) {
				mid = 1;
				break;
			}
		}
		if (mid == 0) {
			duan[k].x1=xy[i][0];
			duan[k].y1=xy[i][1];
			duan[k].x2=xy[i][2];
			duan[k].y2=xy[i][3];
			k++;
		}
	}
	for (int i = 0; i <= k; i++) { //连接中。。。
		for (int j = 0; j < n; j++) {
			if ((duan[i].x2 == xy[j][0]) && (duan[i].y2 == xy[j][1])) {
				duan[i].x2 = xy[j][2];
				duan[i].y2 = xy[j][3];
				duan[i].num++;
				j = 0;
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		if (max < duan[i].num) {
			max = duan[i].num;
			tem = i;
		}
	}
	printf("%d %d %d", duan[tem].num+1, duan[tem].x1, duan[tem].y1);
}

