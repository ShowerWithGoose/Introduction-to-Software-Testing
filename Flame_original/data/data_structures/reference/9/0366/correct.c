#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
 typedef struct zuobiao{
 	int line_num;
 	int x_1;
 	int y_1;
 	int x_2;
 	int y_2;
 }zuobiao[102];
 int main(){
 	struct zuobiao zuobiao[102];
 	int n;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++){
 		scanf("%d %d %d %d",&zuobiao[i].x_1,&zuobiao[i].y_1,&zuobiao[i].x_2,&zuobiao[i].y_2);
 		zuobiao[i].line_num=1;
	}
	int temp_x_1=0,temp_y_1=0;
	int temp_x_2=0,temp_y_2=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(zuobiao[j].x_1>zuobiao[i].x_1){
				temp_x_1=zuobiao[j].x_1;
				zuobiao[j].x_1=zuobiao[i].x_1;
				zuobiao[i].x_1=temp_x_1;    
				temp_y_1=zuobiao[j].y_1;
				zuobiao[j].y_1=zuobiao[i].y_1;
				zuobiao[i].y_1=temp_y_1;
				temp_x_2=zuobiao[j].x_2;
				zuobiao[j].x_2=zuobiao[i].x_2;
				zuobiao[i].x_2=temp_x_2;    
				temp_y_2=zuobiao[j].y_2;
				zuobiao[j].y_2=zuobiao[i].y_2;
				zuobiao[i].y_2=temp_y_2;                 
			}
			if(zuobiao[j].x_1==zuobiao[i].x_1){
				if(zuobiao[j].y_1<zuobiao[i].y_1){
				temp_x_1=zuobiao[j].x_1;
				zuobiao[j].x_1=zuobiao[i].x_1;
				zuobiao[i].x_1=temp_x_1;    
				temp_y_1=zuobiao[j].y_1;
				zuobiao[j].y_1=zuobiao[i].y_1;
				zuobiao[i].y_1=temp_y_1;
				temp_x_2=zuobiao[j].x_2;
				zuobiao[j].x_2=zuobiao[i].x_2;
				zuobiao[i].x_2=temp_x_2;    
				temp_y_2=zuobiao[j].y_2;
				zuobiao[j].y_2=zuobiao[i].y_2;
				zuobiao[i].y_2=temp_y_2;                    
				}	
			}
		}	
	} 
	int x_max,y_max;
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(zuobiao[i].x_1==zuobiao[j].x_2 && zuobiao[i].y_1==zuobiao[j].y_2){
				zuobiao[j].line_num+=zuobiao[i].line_num;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(zuobiao[i].line_num>max){
			max=zuobiao[i].line_num;
			x_max=zuobiao[i].x_1;
			y_max=zuobiao[i].y_1;
		}
	}
	printf("%d %d %d",max,x_max,y_max);
	return 0;
 }

