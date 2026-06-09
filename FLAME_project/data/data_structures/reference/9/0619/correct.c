#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void swap(int*,int*);
int main()
{
	int n;
	scanf("%d",&n);
	int x1[1000],x2[1000],y1[1000],y2[1000];
	for(int i = 0;i < n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(int i = 0;i < n - 1 ;i++){
		for(int j = 0;j < n - 1 - i ;j++){
			if(x1[j] > x1[j + 1]){
				swap(&x1[j],&x1[j+1]);
				swap(&x2[j],&x2[j+1]);
				swap(&y1[j],&y1[j+1]);
				swap(&y2[j],&y2[j+1]);
			}
		}
	}
/*	for(int i = 0;i < n;i++){
		printf("%d %d % d %d\n",x1[i],y1[i],x2[i],y2[i]);
	}*/
	 int num,max = 0;
	int frist_x,frist_y,temp;
	for(int i = 0;i < n ;i++){
		temp = i;
		num = 1;
		for(int j = i + 1;j < n;j++){
			if(x1[j]==x2[temp]&&y1[j]==y2[temp]){
				num++;
				temp = j;
			}
		}
		if(num > max){
			max = num;
			frist_x = x1[i];
			frist_y = y1[i];
		} 
	}
	printf("%d %d %d",max,frist_x,frist_y);
	return 0;
}
void swap(int *num1,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



