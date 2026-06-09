#include<stdio.h>
#include<stdlib.h>
int cmp(const void *, const void *);
int a[205][4];
int cnt[205];
int main()
{
	int i, j;
	int n;
	int now_x, now_y;
	int max = 1, max_i;
	scanf("%d", &n);
	for( i=0; i<n; i++ ) 
		scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	qsort(a, n, sizeof(a[0]), cmp);
	for( i=0; i<n; i++ ) {
		now_x = a[i][2];
		now_y = a[i][3];
		for( j=i+1; j<n; j++ ) {
			if( a[j][0]==now_x && a[j][1]==now_y ) {
				now_x = a[j][2];
				now_y = a[j][3];
				cnt[i]++;
			}
		}
	}
	for( i=0; i<n; i++ ) {
		if( cnt[i]+1 > max ) {
			max = cnt[i] + 1;
			max_i = i;
		}
	}
	printf("%d %d %d\n", max, a[max_i][0], a[max_i][1]);
	return 0;
}

int cmp(const void *x, const void *y)
{
	int *x1 = (int*)x, *y1 = (int *)y;
	if( x1[0] > y1[0] ) return 1;
	else if( x1[0] < y1[0] ) return -1;
	return 0;
}  


