#include <stdio.h>

int M[10] = {0}; 
char s[11]; 
int N;

void rank(int, int); 				  

int main ()
{
	scanf ("%d",&N);	
	rank(0,N);	
	return 0;
}
void rank(int m, int n)
{
	int i,j;
	if( n == 0){ 
		for(j=0;j<m;j++)
		printf("%c ",s[j]);
		printf("\n");
		return;
	}
	for(i=1; i<=N; i++)
		if(M[i] == 0 ){
			M[i] = 1; 	/* 标记该数字已被使用*/
			s[m] = '0'+i;  	/*将当前数字加到全排列数字串中*/
			rank(m+1,n-1); 	/* 生成全排列中下一个数字 */
			M[i] = 0;	/*释放该数字*/
		}
		
}

