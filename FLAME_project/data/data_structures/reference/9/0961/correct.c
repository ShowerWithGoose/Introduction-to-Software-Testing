#include<stdio.h>
#include<string.h>
int final[2];
int main(){
	struct Line{
		int x1;
		int y1;
		int x2;
		int y2;
	}line[101];
	int length;
	scanf("%d",&length);
	for(int i=0;i<length;i++){
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	int num=1,max=0,k;
	for( int i=0; i<length; i++)
	{
		k=i;
		int j=0;
		while(j<length){
			if(line[k].x2==line[j].x1 && line[k].y2==line[j].y1){
				num++; 
				k=j;
				j=0;
				}
			else j++;
		}
		if(num>max){
			max=num;
			final[0]=line[i].x1;
			final[1]=line[i].y1;
		}
		num=1;
	}
	printf("%d %d %d",max,final[0],final[1]);
} 

