#include <stdio.h>
#include <stdlib.h>
struct line{
		int x1;
		int y1;
		int x2;
		int y2;
		int cnt;
	};
int main(){
	int n;
	scanf("%d", &n);
	struct line kai[200];
	struct line over[200];
	int i=0, j=0, k=0;
	for (i=0; i<n; i++){
		scanf("%d%d%d%d", &kai[i].x1, &kai[i].y1, &kai[i].x2, &kai[i].y2);
	}
	int flag = 0;
	for (i=0; i<n; i++){
		flag = 0;
		for (j=0; j<n; j++){
			if (i==j) continue;
			if (kai[i].x1==kai[j].x2 && kai[i].y1==kai[j].y2){
				flag = 1;
				break;
			}
			
			
			
		}
		if (flag == 0){
				over[k].x1 = kai[i].x1;
				over[k].x2 = kai[i].x2;
				over[k].y1 = kai[i].y1;
				over[k].y2 = kai[i].y2;
				k++;
			}
	}
	for (i=0; i<k; i++){
		over[i].cnt = 1;
		for (j=0; j<n; j++){
			if (over[i].x2 == kai[j].x1 && over[i].y2 == kai[j].y1){
				over[i].x2 = kai[j].x2;
				over[i].y2 = kai[j].y2;
				over[i].cnt ++;
				j=-1;
			}
		} 
	}
	int max=0, ans=0;
	for (i=0; i<k; i++){
		if (over[i].cnt > max){
			max = over[i].cnt;
			ans = i;
		}
	}
	printf("%d %d %d", max, over[ans].x1, over[ans].y1);
	
	
	
	
	
	
	
	return 0;
}

