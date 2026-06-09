#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	
};
struct line line1[105];
int main(){
	int n;
	scanf("%d",&n);
	int i = 0;
	for(i= 0;i<n;i++){
		scanf("%d %d %d %d",&line1[i].x1,&line1[i].y1,&line1[i].x2,&line1[i].y2);
	}
	int xmin,ymin,temp;
	int maxnumber = 0;
	int count = 1;
	for(i=0;i<n;i++){
		count = 1;
		temp = i;
		int j =0;
		for(;j<n;j++){
			if(line1[temp].x2==line1[j].x1&&line1[temp].y2==line1[j].y1){
				count++;
				temp = j;
				j = -1;
			}
		}
		if(count>maxnumber){
			maxnumber = count;
			xmin = line1[i].x1;
			ymin = line1[i].y1;
		}
	}
	printf("%d %d %d",maxnumber,xmin,ymin);
		
	
	
	
	
	
	
	
	
	
	
	return 0;
} 



