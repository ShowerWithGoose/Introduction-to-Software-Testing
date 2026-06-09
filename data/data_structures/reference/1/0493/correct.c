#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100000
int f[19];
char t[19];
void show(char *x,int l){
	int i;
	for(i=0;i<l;i++)
		printf("%c ",x[i]);
	printf("\n");
}
void pailie(char * a,int n,int len)
{
	int i;
	char temp;
	
	if(n==len)
		show(t,len);
		
		
else
	for(i=0;i<len;i++){
		if(f[i]==0){
			t[n]=a[i];
			f[i]=1;
		pailie(a,n+1,len);
		f[i]=0;
		}
		
	}
}
int main(){
	int n;
	scanf("%d",&n);
	char a[1000];
	int i;
	for(i=1;i<=n;i++)
		a[i-1]=i+48;
	pailie(a,0,n);
	
	return 0;
} 

