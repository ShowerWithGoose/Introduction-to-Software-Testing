#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct zuobiao {
	int x1;
	int y1;
	int x2;
	int y2;
};//坐标
int main() {
	struct zuobiao a[200];
	int i=0,n,j=0;
	struct zuobiao hold;


	int MAXLINE=1;//定义一个最多线段数
	int X1=0,Y1=0;//定义最多线段数的起始坐标



	scanf("%d",&n);//输入线段数
	for(i=0; i<n; i++) {
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}//输入每个线段的坐标
//排序

	for (i = 0; i < n; i++) {
		for (j =i; j < n; j++) {
			if (a[i].x1 > a[j].x1) {
				hold = a[i];
				a[i]= a[j];
				a[j] = hold;

			}
		}

	}



	for(i=0; i<n; i++) {
		int flag=1;
	
		for(j=i; j<n; j++) {
			if(a[i].x2==a[j+1].x1&&a[i].y2==a[j+1].y1) {
				flag++;
				a[i].x2=a[j+1].x2;
				a[i].y2=a[j+1].y2;
			}
		}
		if(flag>=MAXLINE) {
			MAXLINE=flag;
			X1=a[i].x1;
			Y1=a[i].y1;
		}
	}



	printf("%d %d %d\n",MAXLINE,X1,Y1);
	return 0;
}

