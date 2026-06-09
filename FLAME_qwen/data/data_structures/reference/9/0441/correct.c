#include <stdio.h>

typedef struct lines
{
	int x1;
	int y1;
	int x2;
	int y2;
}lines;

lines line[252];

int main ()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
	}
	
	for(int i = 0 ; i < n - 1 ; i ++){
		int flag = 1;
		for(int j = 0 ; j < n - i - 1 ; j ++)
		{
			if(line[j].x1 > line[j + 1].x1){
				lines t;
				t = line[j];
				line[j] = line[j + 1];
				line[j + 1] = t;
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
	/*for(int i = 0 ; i < n ; i ++){
		printf("%d ", line[i].x1);
	}*/
	
	lines linest = line[0];
	int max = 0;
	int index;
	for(int i = 0 ; i < n ; i ++){
		index = 1;
		int x = line[i].x2, y = line[i].y2;
		for(int j = i + 1 ; j < n ; j ++){
			if(x == line[j].x1 && y == line[j].y1){
				index ++;
				x = line[j].x2, y = line[j].y2;  
			}
		}
		if(index >= max){
			max = index;
			linest = line[i];
		}
	}
	
	printf("%d %d %d", max, linest.x1, linest.y1);
	return 0;
}

