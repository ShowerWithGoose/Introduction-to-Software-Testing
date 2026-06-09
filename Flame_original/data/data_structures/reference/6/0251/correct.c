#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
  int x,y;
  int a[100];
  int top=-1;
  while(x!=-1)
  {
  	scanf("%d",&x);
  	
  	
  	if(x==0)
  	{
  	if(top==-1)
   {
    printf("error ");
   }
   else
   {
    printf("%d ",a[top--]);
   }	
	  }
	  
	  if(x==1)
	  {
	  	scanf("%d",&y);
	  	if(top==99)
	  	{
	  		printf("error ");
		  }
		  else
		 {
		 top++;
		 a[top]=y;
		 }
	  }
	  
  }
  return 0;
 } 

