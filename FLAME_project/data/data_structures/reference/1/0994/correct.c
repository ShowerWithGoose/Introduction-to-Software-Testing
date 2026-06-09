#include<stdio.h>

#include<string.h>

#include<math.h>

#include<ctype.h>

#include<stdlib.h>

#define MAX_N 10

int Line_Number[MAX_N];

int tag[MAX_N];

void dps(int );

int n;

int main (){
	
	while(scanf("%d",&n)!=EOF){
		
		dps(n);
		
	}
	
	return 0;
}
void dps(int t){
	
	if(t==0){//递归完毕，输出排列数 
	
		for(int i=0;i<n;++i){
	
			printf("%d",Line_Number[i]);
	
			if(i==n-1){
	
				putchar('\n');
	
			}
		
			else 
		
				putchar(' ');
		
		}
		
		return ;
	}
	
	else{
		
		for(int i=1;i<=n;++i){//由大到小有规律地排列 
			
			if(tag[i]==0){
				
				Line_Number[n-t]=i;
				
				tag[i]=1;
				
				dps(t-1);//递归还可以选中的数 
				
				tag[i]=0;
				
			}
		}
	}
}

