#include<stdio.h>
void planting(int x1,int y1);
int X1[1000],Y1[1000],X2[1000],Y2[1000],cont[102],record[102][3],best[3];
int N,max=1,z=0;
int main() {
	int i;
	scanf("%d",&N);
	for(i=1; i<=N; i++) {
		scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
	}
	for(i=1; i<=N; i++) {
		z++;
		cont[z]++;
        record[i][1]=X1[i],record[i][2]=Y1[i];
        planting(X2[i],Y2[i]);
	}
	for(i=1; i<=N+1; i++) {
		if(cont[i]>max) {
			max=cont[i];
			best[1]=record[i][1];
			best[2]=record[i][2];
		}
		
		}
printf("%d %d %d",max,best[1],best[2]);
		
	
	return 0;
	}
void planting(int x1,int y1) {
	int i;
	for(i=1; i<=N; i++) {
			if(x1==X1[i]&&y1==Y1[i]) {
				cont[z]++;
				planting(X2[i],Y2[i]);
			}
	}
}




