#include <stdio.h>

int M[10] = {0}; 
char N[11]; 
int k;

void rank(int, int); 				  

int main ()
{
	scanf ("%d",&k);	
	rank(0,k);	
	return 0;
}
void rank(int m, int n)
{
	int i,a;
	if( n == 0){ 
		for(a=0;a<m;a++)
		printf("%c ",N[a]);
		printf("\n");
		return;
	}
	for(i=1; i<=k; i++)
		if(M[i] == 0 ){
			M[i] = 1; 	/* 标记该数字已被使用*/
			N[m] = '0'+i;  	/*将当前数字加到全排列数字串中*/
			rank(m+1,n-1); 	/* 生成全排列中下一个数字 */
			M[i] = 0;	/*释放该数字*/
		}
		
}

