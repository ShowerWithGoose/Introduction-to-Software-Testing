#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
int a[50]={0},b[50]={0};
void f(int m,int n);
int main(){
	int n;
	scanf("%d",&n);
	f(1,n);
} 
void f(m,n){
	int i;
	if(m>n){
		for(i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
		return;
	}
	for(i=1;i<=n;i++)
		if(b[i]==0){
			b[i]=1;
			a[m]=i;
			f(m+1,n);
			b[i]=0;
		}
}

