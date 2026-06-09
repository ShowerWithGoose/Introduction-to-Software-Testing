#include<stdio.h>
#include<stdlib.h>
/*
1 定义结构体，结构体包含：线段数量，线段终点坐标
2 如果输入线段的起点与某结构体数组中，线段终点坐标相同，则更新并count++
3 没了
*/
struct point {
	int x;
	int y;
} tmpStartPoint, tmpEndPoint; //tmpPoint为输入时的临时点坐标
struct line {
	int cnt;
	struct point startPoint;
	struct point endPoint;
} lines[105];
int cmp(const void*a ,const void* b)
{
	int*x=(int*)a;
	int*y=(int*)b;
	return(*(x+0)-*(y+0));
}
int main() {
	int n;
	int a[105][4];
	scanf("%d ", &n);
	for (int i = 0; i < 105; i++) {
		lines[i].cnt = 0;  //将所有线段的cnt归零
	}
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d ",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	qsort(a,n,sizeof(a[0]),cmp);

	int linesCount = 0;
	for (int i = 0; i < n; i++) {
		/*
			输入起点；找起点，没有则存并更新终点，有则在原基础上更新终点
		*/
		tmpStartPoint.x=a[i][0],tmpStartPoint.y=a[i][1],tmpEndPoint.x=a[i][2],tmpEndPoint.y=a[i][3];
		int flag=0;
		for (int j = 0; j < linesCount; j++) {
			if (lines[j].endPoint.x == tmpStartPoint.x && lines[j].endPoint.y == tmpStartPoint.y) {
				lines[j].endPoint = tmpEndPoint;
				lines[j].cnt++;
				flag=1;
				break;
			} 
			else if (lines[j].startPoint.x == tmpEndPoint.x && lines[j].startPoint.y == tmpEndPoint.y) {
				lines[j].startPoint = tmpStartPoint;
				lines[j].cnt++;
				flag=1;
				break;
			} 
		}
		if(flag==0){
			lines[linesCount].startPoint = tmpStartPoint;
			lines[linesCount].endPoint = tmpEndPoint;
			lines[linesCount].cnt++;
			linesCount++;
		}
	}
	int maxCnt = 0, m = 0;
	for (int i = 0; i < linesCount; i++) {
		//查找最大的cnt对应的结构体，输出intialPoint
		if (maxCnt <= lines[i].cnt) {
			maxCnt = lines[i].cnt;
			m = i;
		}
	}
	printf("%d %d %d", lines[m].cnt, lines[m].startPoint.x, lines[m].startPoint.y);
	return 0;
}

