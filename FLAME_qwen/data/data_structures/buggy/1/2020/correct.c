
#include <stdio.h>
int M[10] = {0}; 
char S[20]; 
void r(int m, int n); 				  
int N;
int main ()
{
	scanf("%d", &N);	
	r(0,N);	
	return 0;
}
void r(int m, int n)
{
	int i;
	if(n==0){ 
		S[m] = '\0';
		for(i=0;i<N;i++){
			printf("%c ",S[i]);
		}
			printf("\n");	
		return;
	}
	for(i=1; i<=N; i++)
		if(M[i]==0){
			M[i]=1; 	
			S[m]='0'+i;  	
			r(m+1,n-1); 	
			M[i]=0;
		}	
}





