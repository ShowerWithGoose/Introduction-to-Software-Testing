#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int l;
	int r;
}point,now;
int main()
{
	int n;
	int max = 0;
	scanf("%d",&n);
	struct line group[n];
	for(int i = 0;i<n;i++){
		scanf("%d%d%d%d",&group[i].x1,&group[i].y1,&group[i].x2,&group[i].y2);
		group[i].l=-1;
		group[i].r=-1;
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(j == i){
				continue;
			}
			else{
				if(group[i].x2==group[j].x1&&group[i].y2==group[j].y1){
					group[i].r = j;
					group[j].l = i;
				}
			}
		}
	}

	for(int i = 0;i<n;i++){
		int res = 0;
		if(group[i].l == -1&&group[i].r!=-1){
			now = group[i];
			res++;
			while(group[now.r].r!=-1){
				res++;
				now = group[now.r];
			}
			res++;
			if(res>=max){
				max = res;
				point = group[i];
			}
		}
	}
		//	printf("here");
	printf("%d %d %d",max,point.x1,point.y1);
	return 0;
}

