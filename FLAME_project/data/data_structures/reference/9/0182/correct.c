#include <stdio.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct line arr[120];
struct line war;
int find(int n){
	int i;
	for(i=0;i<n;i++){
		if(war.x2==arr[i].x1&&war.y2==arr[i].y1){
			war=arr[i];
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
	}
	int count=1,max=0;
	struct line maxline;
	for(i=0;i<n;i++){
		struct line temp=arr[i];
		count=1;
		war=temp;
		while(1){
			if(find(n)==0){
				break;
			}
			count++;
		}
		if(count>max){
			max=count;
			maxline=temp;
		}
	}
	printf("%d %d %d",max,maxline.x1,maxline.y1);
	return 0;
} 

