#include<stdio.h>
int mark[101] = {0}, count[101] = {0};
int main(){
	int lines[101][4], N, i, j, max = 0, m;
	fscanf(stdin, "%d", &N);
	for(i = 0; i < N; i++)
		for(j = 0; j < 4; j++)
			fscanf(stdin, "%d", &lines[i][j]);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(lines[i][2] == lines[j][0] && lines[i][3] == lines[j][1])
				mark[i+1] = j+1;
		}
	}
//	printf("%d%d%d\n",mark[0], mark[1], mark[2]);
	for(i = 1; i <= N; i++){
		int temp = i;
		count[i] = 1;
		while(mark[temp] != 0){
			count[i]++;
			temp = mark[temp];
		}
	}
//	for(i = 0; i < N; i++){
//		printf("%d\n", count[i]);
//	}
	
	for(i = 1; i <= N; i++){
		if(count[i] > max){
			max = count[i];
			m = i-1;
		}
	}
	fprintf(stdout,"%d %d %d", max, lines[m][0], lines[m][1]);
} 



