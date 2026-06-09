#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x1;
	int y1;
	int x2;
	int y2;
} lnode;

lnode line[103];
int cmp(const void *p, const void *q) {
	return (((lnode *)p)->x1) - (((lnode *)q)->x1);
}

int main() {
	int N;
	fscanf(stdin, "%d", &N);
	for (int i = 0; i < N; i++) { //input
		fscanf(stdin, "%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
	}
	qsort(line, N, sizeof(lnode), cmp);
    int maxl = -1,maxx,maxy;
    for(int i = 0;i<N;i++){
        int nowL = 1,nowid = i;
        int flag = 1;
        for(int j = i+1;j<N;j++){
            if(line[j].x1==line[nowid].x2 && line[j].y1==line[nowid].y2){
                nowL++;
                nowid = j;
            }
        }
        if(nowL>maxl){
            maxl = nowL;
            maxx = line[i].x1;
            maxy = line[i].y1;
        }
    }
    printf("%d %d %d",maxl,maxx,maxy);
}



