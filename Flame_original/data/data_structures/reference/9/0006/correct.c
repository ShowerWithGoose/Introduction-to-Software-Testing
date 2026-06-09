#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}list[100];
int n, m, max_m, max_i, t;
int find(int x){
	for (int i=0; i<n; i++){
		if(i==x)continue;
		if (list[x].x2==list[i].x1 && list[x].y2==list[i].y1){
			return i;
		}
	}
	return -1;
}

int main(){
	scanf ("%d", &n);
	for (int i=0; i<n; i++){
		scanf ("%d%d%d%d", &list[i].x1, &list[i].y1, &list[i].x2, &list[i].y2);
	}
	for (int i=0; i<n; i++){
		m=1;
		t=i;
		while((t=find(t))!=-1){
			m++;
		}
		if(m>max_m){
			max_m=m;max_i=i;
		}
	}
	printf ("%d %d %d", max_m, list[max_i].x1, list[max_i].y1);
	return 0;
}



