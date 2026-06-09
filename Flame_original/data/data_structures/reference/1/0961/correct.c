#include <stdio.h>
int Stack[11]; 

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
	int i,j;

	if( m == n){ 
	   for(i=0;i<n;i++){
	   	printf("%d ",Stack[i]);
	   }
	   printf("\n");
		return;
	}
	for(i=1; i<=n; i++)
	{
		int ok=1;
		for(j=0;j<m;j++){
			if(Stack[j]==i ) ok = 0;
		}
	if( ok==1 ){
		  Stack[m]=i; 
			rank(m+1,n); 		
	}
}
}
		





