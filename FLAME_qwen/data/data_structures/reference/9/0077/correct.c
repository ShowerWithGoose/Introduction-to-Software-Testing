#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
	int first[3];
	int last[3];
	int cnt;
}LINE;
LINE line[120];
int compare(const void* a,const void* b);
int compare2(const void* a,const void* b); 
int main()
{	
	int N;
	int flag=0;
	int i=0,j=0,k=0,l;            
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&line[i].first[0],&line[i].first[1],&line[i].last[0],&line[i].last[1]);
		line[i].cnt=1;
	} 
	qsort(line,N,sizeof(LINE),compare); //现在line里面有N个结构体，按照x1从小到大排序 
	for(i=1;i<N;i++){ //新 
		for(j=0;j<i;j++){ //旧 
	//	flag=0;
			if(line[i].first[0]==line[j].last[0] && line[i].first[1]==line[j].last[1]){
				line[j].last[0]=line[i].last[0];
				line[j].last[1]=line[i].last[1];
				line[i].cnt=-1;
				line[j].cnt++;
			//	flag=1;
			}
		}
	}
	qsort(line,N,sizeof(LINE),compare2);
	printf("%d %d %d",line[0].cnt,line[0].first[0],line[0].first[1]);
 return 0;
}
int compare(const void* a,const void* b){
	LINE* pa=(LINE*)a;
	LINE* pb=(LINE*)b;
	int num1=pa->first[0];
	int num2=pb->first[0];
	return num1-num2;     //升序 
	}
int compare2(const void* a,const void* b){
	LINE* pa=(LINE*)a;
	LINE* pb=(LINE*)b;
	int num1=pa->cnt;
	int num2=pb->cnt;
	return num2-num1;     //降序 
	
}
	//当遍历之前的所有，发现有相等的，就把该位置替换为新的终点，删除新点的坐标（把它的cnt设置为-1） 
	//如果没有相等的，位置不动 
	//最终line里还是N个结构体，但是有的结构体cnt是-1，排序会排到后面 ，有的结构体cnt是自己，是1，也会往后排，所以一共排N个结构体 

