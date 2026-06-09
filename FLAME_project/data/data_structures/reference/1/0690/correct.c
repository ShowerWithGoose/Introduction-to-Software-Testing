#include <stdio.h>
int flag[10] = {0},n; 
char s[15]; 
void rank(int m, int x){
	int i;
	if( x == 0){ 
		for(i=0;i<n;i++)
		printf("%c ",s[i]);
		printf("\n");	
		return;
	}
	for(i=1; i<=n; i++)
		if(flag[i] == 0 ){
			flag[i] = 1;
			s[m] = '0'+i;
			rank(m+1,x-1); 
			flag[i] = 0;
		}
}	  
int main ()
{
	scanf("%d", &n);	
	rank(0,n);	
	return 0;
}





