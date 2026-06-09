#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void exchange(int arr[], int a, int b);
void full_permutation(int num,int all);
int cmp(const void *a,const void *b);
int top=0;
int arr[20] = {0};//arr定义到方法里面似乎出来的都是地址值
int cnt=0;
char str[16000][20];
int main()
{
	int n;
	scanf("%d",&n);
	full_permutation(n,n);
	qsort(str,cnt,sizeof(str[0]),cmp);
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<n;j++)
		printf("%c ",str[i][j]);
		printf("\n");
	}
	return 0;
 } 
int cmp(const void *a,const void *b)
{
	char *aa = (char *)a;
	char *bb = (char *)b;
	if(strcmp(aa,bb) > 0)
		return 1;
	return -1;
	
}
void exchange(int arr[], int a, int b) 
{
 int replace = arr[a];
 arr[a] = arr[b];
 arr[b]=replace;
}
void full_permutation(int num,int all)
 {
   //递归实现全排列，如输入3， 输出1 2 3，1 3 2，2 1 3 ，2 3 1，3 2 1，3 1 2     
   //num是进行到第几个大循环，all是一共有几个数
 	if (num == all) 
	{
 		 for (int q = 0; q< all; q++)
		  {
 	  			arr[q] = q + 1;//初始化数组
 		 }
 	}
 	if (num==1) 
	{
		int p=0;
  		for (int i=all-1; i >=0; i--)
	  	 {
	  	 	str[top][p] = arr[i] + '0' ;
	  	 	p++;
  	 		//printf("%d", arr[i] );
  		}	
  		top++;
  		cnt++;
 		// putchar('\n');
 	}//结束循环条件
 	for (int b = 0; b < num; b++) 
	{
  		exchange(arr, num-1, num-1 - b);//交换
  		full_permutation(num-1,all);//进入下一层
  		exchange(arr, num-1, num-1- b);//交换回去
 	}
}




