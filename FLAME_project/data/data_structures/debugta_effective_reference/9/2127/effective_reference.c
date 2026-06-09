//第三次第一题
#include <stdio.h>
#include <string.h>

typedef struct xian {
	int a1;
	int b1;
	int a2;
	int b2;
	int num;//线段长度
	//线段的两个端点为v1(a1,b1)和v2(a2,b2)
} x;

int main() {
	x XY[150];//线段个数小于等于100 此处设置了150条线段
	int n;
	int i,j;
	scanf("%d",&n);//读取线段数
	for(i=0; i<n; i++)
		scanf("%d %d %d %d", &XY[i].a1, &XY[i].b1, &XY[i].a2, &XY[i].b2);//读取各线段两个端点的x、y坐标
	//先排序，如题使得线段的横坐标从小到大排序
	x tmp;//临时置换线段
	/*
		for(i=0; i<n; i++)//将前一个和后一个作比较，将横坐标较大的放到后面去
			for(j=i; j<n; j++) {
				if(info[i].a1 > info[j].a1) {
					tmp = info[i];
					info[i] = info[j];
					info[j] = tmp;
				}
			}
			*/
	i=0;
	while(i<n) {
		for(j=i; j<n; j++) {
			if(XY[i].a1 > XY[j].a1) {
				tmp = XY[i];
				XY[i] = XY[j];
				XY[j] = tmp;
			}
		}
		i++;
	}
	int count_max=1,a1_max = 0,b1_max = 0;//最长线段

	i=0;
	while(i<n) {
		int a2,b2,count=1;//(a2，b2)是每个线段后面的那个点
		a2=XY[i].a2;
		b2=XY[i].b2;
		j=i+1;
		while(j<n) {
			if( a2==XY[j].a1 && b2==XY[j].b1 ) { //i的终点v2与j的起点相等，即为前面的第二个点与后一个的第一个点相同
				count++;//线段数+1（
				a2=XY[j].a2;//将i变成j，即不断地挪步，原来前者第二个点变成原来后者第二个点
				b2=XY[j].b2;
			}
			if(count > count_max) {//如果刚运算的最大长度比已有最大长度的值大，则将刚运算的长度值储存为新的最大长度值
				count_max=count;
				a1_max=XY[i].a1;//起点横坐标更新
				b1_max=XY[i].b1;//纵坐标更新
			}
			j++;
		}
		i++;
	}
	//	for(i=0; i<n; i++) {
	/*
		int a2,b2,count=1;//(a2，b2)是每个线段后面的那个点
		a2=info[i].a2;
		b2=info[i].b2;
				for(j=i+1; j<n; j++) {//(x1,y1)是按顺序后一个线段的前面的那个点
					if( a2==info[j].a1 && b2==info[j].b1 ) { //i的终点v2与j的起点相等，即为前面的第二个点与后一个的第一个点相同
						count++;//线段数+1（
						a2=info[j].a2;//将i变成j，即不断地挪步，原来前者第二个点变成原来后者第二个点
						b2=info[j].b2;
					}
					if(count > count_max) {//如果刚运算的最大长度比已有最大长度的值大，则将刚运算的长度值储存为新的最大长度值
						count_max=count;
						a1_max=info[i].a1;//起点横坐标更新
						b1_max=info[i].b1;//纵坐标更新
					}
				}

			}
		*/

	printf("%d %d %d\n", count_max, a1_max,b1_max);
	//输出包含最多线段数的连续线段的线段数，然后输出连续线段的起点的x、y坐标
	return 0;
}



