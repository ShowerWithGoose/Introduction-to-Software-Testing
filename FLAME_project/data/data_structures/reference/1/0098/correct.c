#include <stdio.h>
#define MAX 11
int N;
int Mark[MAX] = {0}; 
char Stack[MAX];
void rank(int m, int n); 
int main ()
{
	scanf ("%d", &N);	
    rank(0,N);	
    return 0;
}

void rank(int m, int n)
{
	int i,j;
	if( n == 0){ 
		Stack[m] = '\0';
		//puts(Stack);
		for(j=0;j<N;j++){
			printf("%d ",Stack[j]-'0');
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


