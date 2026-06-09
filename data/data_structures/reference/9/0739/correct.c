#include <stdio.h>
#include <stdlib.h>


int point[105][4];
int ans, max = 0;
int an1, an2, x;
void rever(int s[][4], int n);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void rever(int s[][4], int n){
	int p = 0, q = 0, k = 0, tem[5];
	for(p = 0;p < n;p++){
		for(q = p + 1;q < n;q++){
			if(s[p][0] > s[q][0]){
				for(k = 0;k < 4;k++){
					tem[k] = s[p][k];
				}
				for(k = 0;k < 4;k++){
					s[p][k] = s[q][k];
				}
				for(k = 0;k < 4;k++){
					s[q][k] = tem[k];
				}
			}
		}
	}
	return; 
}

int main(int argc, char *argv[]) {
	int num;
	int i , j;
	scanf("%d", &num);
	for(i = 0;i < num;i++){
		scanf("%d%d%d%d", &point[i][0], &point[i][1], &point[i][2], &point[i][3]);
	}
	rever(point, num);
	for(i = 0;i < num;i++){
		ans = 1;
		x = i;
		for(j = i + 1;j < num;j++){
			if(point[x][2] == point[j][0]&&point[x][3] == point[j][1]){
				ans++;
				x = j;
			}
		}
		if(ans > max){
			max = ans;
			an1 = point[i][0], an2 = point[i][1];
		}
	}
	printf("%d %d %d\n", max, an1, an2);
	return 0;
}




