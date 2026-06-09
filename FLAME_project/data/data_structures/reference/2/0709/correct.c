#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define eps 1e-15
char s[100000];
char a[100000];
int num1[1000000][20];
int wei[100000];
int num2[100000];
int sum[10000000];

void delate_space( );
void store();
long long work();

int main(){
	gets(s);
	
	delate_space( );//去除空格 
	store();//将数据存储 
	
	printf("%lld",work()); 

	return 0;
}

void delate_space( ){
	for(int i=0,j=0;i<strlen(s);i++)
	{
		if(s[i] == ' ')
			continue;
		else
		{
			a[j] = s[i];
			j++;
		}
	}
	
	return ;
}
void store(){
	int j=0,weishu=1;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			num1[j][wei[j]] = a[i]-48;
			wei[j]++;
		}
		else
			j++;
	}
	for(int i=0;i<=j;i++){
		for(int k=wei[i];k>=0;k--){
			num2[i] += num1[i][k-1] * weishu;
			weishu *= 10;
		}
		weishu = 1;
	}
	return ;
}
long long work(){
	long long outcome;
	
	sum[0] = num2[0];
	for(int i=0,j=0,k=0;i<strlen(a);i++)
	{
		if(a[i] == '+' || a[i] == '-')
			sum[++j] = num2[++k];
		
		else if(a[i] == '*')
			sum[j] *= num2[++k];
		
		else if(a[i] == '/')
			sum[j] /= num2[++k];
		
		else
			continue;; 
	}
	
	outcome = sum[0];
	
	for(int i=0,j=0;i<strlen(a);i++)
	{
		if(a[i] == '+')
			outcome += sum[++j];
		else if(a[i] == '-')
			outcome -= sum[++j];
		else
			continue; 
	}
	return outcome;	
}

