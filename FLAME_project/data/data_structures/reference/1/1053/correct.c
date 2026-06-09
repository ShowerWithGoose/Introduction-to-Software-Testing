#include<stdio.h>
#define MAX 11
int Mark[MAX] = {0}; 
char Stack[MAX]; 
void rank(int m, int n); 
int N;

int main(){
	scanf("%d",&N);
	
	rank(0,N);
	
	return 0;
}

void rank(int m, int n)
{
	int i;
	
	if( n == 0){ 
		Stack[m] = '\0';
		for(int i=0;i<N;i++){
			printf("%c ",Stack[i]);
		}
		printf("\n");
		
		return;
	}
	for(i=1; i<=N; i++)
		if(Mark[i] == 0 ){
			Mark[i] = 1; 
			Stack[m] = '0'+i;  
			rank(m+1,n-1); 	
			Mark[i] = 0;	
		}

}

