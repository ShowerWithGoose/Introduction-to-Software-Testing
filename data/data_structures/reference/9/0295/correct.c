#include <stdio.h>
#include <stdlib.h>
typedef struct point {

	int x1, y1, x2, y2;

} dot;
typedef struct answer {
	int x1, y1;
	int cnt;
} ans;
dot line[120];
ans ret[120];
int cmp(const void* a, const void* b) {

	dot m = *((dot*)a);
	dot n = *((dot*)b);
	return m.x1 - n.x1;
}
int cmp2(const void* a, const void* b) {

	ans m = *((ans*)a);
	ans n = *((ans*)b);
	return n.cnt - m.cnt;
}
void connect(dot* start, int i, int n);
dot* search(int key, int n);
int main() {

	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
	}
	qsort(line, n, sizeof(dot), cmp);

	for (i = 0; i < n; i++) {
		ret[i].x1 = line[i].x1;
		ret[i].y1 = line[i].y1;
		ret[i].cnt = 1;
		connect(&line[i], i, n);
	}
	/*for (i = 0; i < n; i++) {
		printf("%d ",ret[i].cnt);
	}*/
	qsort(ret, n, sizeof(ans), cmp2);
	printf("%d %d %d", ret[0].cnt, ret[0].x1, ret[0].y1);
	return 0;

}
void connect(dot* start, int i, int n) {

	dot* current;
	current = search(start->x2, n);
	if (current == NULL) {
		return;
	} else {
		if (start->y2 == current->y1)
			ret[i].cnt++;
		connect(current, i, n);
	}

}
/*dot* search(int key, int n) {
	//dot* current=&line[n/2];
	int left = 0;
	int right = n ;
	int mid;
	if (key > line[n - 1].x1 || key < line[0].x1)
		return NULL;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == line[mid].x1) {
			return &line[mid];
		} else if (key > line[mid].x1) {
			left = mid;
		} else {
			right = mid;
		}

	}

	return NULL;

}*/

dot* search(int key, int n) {
	
	int i;
	for(i=0;i<n;i++){
		
		if(key==line[i].x1){
			return &line[i];
		}
		
	}	
	return NULL;
	
	
}







