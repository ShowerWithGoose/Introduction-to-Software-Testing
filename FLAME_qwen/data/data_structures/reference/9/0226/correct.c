#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	int i, j, k, n, num = 1;
	int l[105][4], temp[4], x, y;
	int max=0;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d%d%d%d", &l[i][0], &l[i][1], &l[i][2], &l[i][3]);
	}
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(l[i][0]>l[j][0]){
				for(k=0; k<4; k++){
					temp[k] = l[i][k];
				}
				for(k=0; k<4; k++){
					l[i][k] = l[j][k];
				}
				for(k=0; k<4; k++){
					l[j][k] = temp[k];
				}
			}
		}
	}
	
	for(i=0; i<n; i++){
		k = i;
		for(j = i+1; j<n; j++){
			if(l[k][2] == l[j][0]&&l[k][3] == l[j][1]){
				k = j;
				num++;
			}
		}
		if(num > max){
			max = num;
			x = l[i][0];
			y = l[i][1];
		}
		num = 1;
	}
	
	printf("%d %d %d", max, x, y);
	
}

