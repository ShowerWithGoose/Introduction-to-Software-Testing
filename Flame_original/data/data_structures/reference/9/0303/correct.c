#include <stdio.h>
struct Line{
	int x1, y1, x2, y2;
	int f1, f2; 
} line[100];

int f[100];
int num[100];	// ÖÈ 
void initBCJ(int n){
	for(int i=0; i<n; i++){
		f[i] = i;
		num[i] = 1;
	}
}

int search(int x){
	if(f[x] == x){
		return x;
	}
	return f[x] = search(f[x]);
}

void merge(int x, int y){
	int x0 = search(x), y0 = search(y);
	f[x0] = y0;
	num[y0] += num[x0];
}

int main(){
	int n;
	scanf("%d", &n);
	initBCJ(n);
	for(int i=0; i<n; i++){
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
		line[i].f1 = line[i].f2 = 0;
		for(int j=0; j<i; j++){
			if(line[i].x1 == line[j].x1 && line[i].y1 == line[j].y1){
				merge(i, j);
				line[i].f1 = line[j].f1 = 1;
			}
			if(line[i].x1 == line[j].x2 && line[i].y1 == line[j].y2){
				merge(i, j);
				line[i].f1 = line[j].f2 = 1;
			}
			if(line[i].x2 == line[j].x1 && line[i].y2 == line[j].y1){
				merge(i, j);
				line[i].f2 = line[j].f1 = 1;
			}
			if(line[i].x2 == line[j].x2 && line[i].y2 == line[j].y2){
				merge(i, j);
				line[i].f2 = line[j].f2 = 1;
			}
		}
	}
	int mx = 0, mxi=-1;
	for(int i=0; i<n; i++){
		//printf("%d %d\n", i, search(i));
		if(mx < num[i]){
			mx = num[i];
			mxi = i;
		}
	}
	
	int x0=2147483647, y0=2147483647;		// ×óÉÏ½Ç×ø±ê 
	for(int i=0; i<n; i++){
		if(search(i) == mxi){
			if(!line[i].f1){
				if(x0 > line[i].x1){
					x0 = line[i].x1;
					y0 = line[i].y1;
				}
			}else if(!line[i].f2){
				if(x0 > line[i].x2){
					x0 = line[i].x2;
					y0 = line[i].y2;
				}
			}
		}
	}
	printf("%d %d %d", mx, x0, y0);
	return 0;
}

