#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
struct location{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
};
struct location point[MAXSIZE];

int cmp(const void *p1, const void *p2){
	struct location *a = (struct location *)p1;
	struct location *b = (struct location *)p2;
	return  a->x1!=b->x1?(a->x1-b->x1):(a->y1-b->y1);
}

int main()
{
	int max=0, max_x=0, max_y=0;
	int i, j, k;
	int n;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d%d%d%d",&point[i].x1, &point[i].y1, &point[i].x2, &point[i].y2);
		point[i].len=1;
	}
	qsort(point, n, sizeof(point[0]), cmp);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==j) continue;
			else{
				if(point[i].x2==point[j].x1&&point[i].y2==point[j].y1){
					point[i].x2=point[j].x2;
					point[i].y2=point[j].y2;
					point[i].len+=point[j].len;
					point[j].len=0;point[j].x1=0;point[j].x2=0;point[j].y1=0;point[j].y2=0;
					if(point[i].len>max){
						max=point[i].len;
						max_x=point[i].x1;
						max_y=point[i].y1;
					}
				}
			}
		}
	}
	printf("%d %d %d",max, max_x, max_y);
}

