#include <stdio.h>
int flag[10]={0}; 
char num[20]; 
void rank(int m, int n); 				  
int N;
int main ()
{
	scanf ("%d",&N);	
	rank(0,N);	
	return 0;
}
void rank(int m,int n)
{
	int i;
	
	if(n==0){ 
		num[m]='\0';
		puts(num);
		return;
	}
	for(i=1; i<=N; i++)
		if(flag[i]==0 ){
			flag[i]=1; 
			num[m]='0'+i;
			num[m+1]=' ';  
			rank(m+2,n-1); 
			flag[i]=0;
		}
		
}





