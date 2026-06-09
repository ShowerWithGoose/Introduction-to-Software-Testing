#include <stdio.h>

int Mark[10] = {0}; 

char Stack[10+1]; 

void rank(int m, int n); 				  
int N;
int main ()
{
	scanf ("%d", &N);	
	rank(0,N);	
	return 0;
}
void rank(int m, int n)
{
	int i;
	
	if( n == 0){ 
		Stack[m] = '\0';
		puts(Stack);
		return;
	}
	for(i=1; i<=N; i++)
		if(Mark[i] == 0 ){
			Mark[i] = 1; 
			Stack[m] = '0'+i;
			Stack[m+1] = ' ';
			rank(m+2,n-1); 
			Mark[i] = 0;
		}
		
}





