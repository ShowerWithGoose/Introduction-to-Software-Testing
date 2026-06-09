#include <stdio.h>
int m[100] = {0}; 
int s[100]; 
void rank(int , int ); 				  
int a;
int main ()
{
	scanf ("%d", &a);	
	rank(0,a);	
	return 0;
}
void rank(int t, int n)
{
	if( t==n ){ 
		for(int i=0;i<n;i++)
		printf("%d ",s[i]);
		printf("\n");
	}
	for(int i=1; i<=n; i++){
		int flag=1;
		for(int j=0;j<t;j++){
			if(s[j]==i) flag=0;
		}
		if(flag){
			s[t]=i;
			rank(t+1,n);
		}
	}
}





