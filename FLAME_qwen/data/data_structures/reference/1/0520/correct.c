#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int n;
int ans[12];
int flag[12]={0}; 
void quanpl(int x);
int main()
{
   scanf("%d",&n);
   
   int i;
   
   quanpl(1);
   
   
	
	
	
	return 0;
 } 
 void quanpl(int x)
 {
 	int i;
 	if(x>n)
 	{
 		for(i=1;i<=n;i++)
 		{
 			printf("%d ",ans[i]);
		 }
		 printf("\n");
	 }
	 else
	 {
	 	for(i=1;i<=n;i++)
	 	{
	 		if(flag[i]==0)
	 		{
	 			flag[i]=1;
	 			ans[x]=i;
	 			quanpl(x+1);
	 			flag[i]=0;
			 }
		 }
	 }
 	
 	
 	
 }



