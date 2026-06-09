#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int used(int);
void put(int);
int check[20]={0},n,a[20];
int main ()
{
	scanf("%d",&n);	
	
	put(0);
	return 0;
 } 
 int used(int t)
 {
 	if (check[t]==0)
 		return 1;
 	return 0;
 }
 void put(int step)
 {
 	
 	int i,j;
 	if (step>=n)
	 {
	 	for (i=0;i<n;i++)
	 	{
	 		printf("%d ",a[i]);
		 }
		 printf("\n");
		 return; 
	 }
	 for (j=1;j<=n;j++)
	 {
	 	if (used(j))
	 	{
	 		a[step]=j;
	 		check[j]=1;
	 		
	 		put (step+1);
	 		check[j]=0;
	 		
		 }
		 
	 }
	 return ;
 }



