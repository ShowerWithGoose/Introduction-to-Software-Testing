#include<stdio.h>  
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{  int num[100],sum=0,a;
   while(scanf("%d",&a)!=EOF)
   {
   	if(a==-1)
   	break;
   	else if(a==1)
   	{
		if(sum==100)
		printf("error ");
		else
		{
		scanf("%d",&a);
   		num[sum++]=a;
		}	
	}
	else if(a==0)
	{
		if(sum==0)
		printf("error ");
		else 
		{
			printf("%d ",num[sum-1]);
			sum--;
		}
	}
   }
     
    return 0;  
}

