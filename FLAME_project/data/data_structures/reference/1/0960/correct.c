#include<stdio.h>
#define MAX 11
int Mark[MAX] = {0}; 
int N;
char Stack[MAX]; /*全排列数字串*/
void rank(int m, int n); /* m记录下一个要生成的全排列数字应放在Stack中的位置，n表示还剩几个数字需要
								生成*/
void rank(int m, int n)
{
	int i;
	
	if( n == 0){ 

		for(i=0;i<m;i++){
			printf("%d ",Stack[i]);
		}
		printf("\n");
	/* 输出全排列数字串*/
		return;
	}
	for(i=1; i<=N; i++)
		if(Mark[i] == 0 ){
			Mark[i] = 1; 	/* 标记该数字已被使用*/
			Stack[m] = i;  	/*将当前数字加到全排列数字串中*/
			rank(m+1,n-1); 	/* 生成全排列中下一个数字 */
			Mark[i] = 0;	/*释放该数字*/
		}

}
int main(){

	scanf("%d",&N);
	rank(0,N);
	return 0;
}
 

