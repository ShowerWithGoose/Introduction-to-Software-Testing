#include<stdio.h>
int box[100]={0};
int top=-1;
int main()
{
	int n,in,out;
	while(1)
	{
	   scanf("%d",&n);
	   if(n==-1)
	   break;
	   else if(n==1)
	   {
	   	  scanf("%d",&in);
	   	  top++;
	   	  box[top]=in;
	   }
	   else
	   {
	   	  if(top<0)
	   	  {
			 printf("error ");
			 continue;
		  }
	   	  if(top==100)
	   	  {
			 printf("error ");
			 continue;
		  }
	   	  printf("%d ",box[top]);
	   	  top--;
	   }
	}
}

