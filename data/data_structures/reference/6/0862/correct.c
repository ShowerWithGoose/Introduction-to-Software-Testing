#include<stdio.h>
#include<math.h>
#include<string.h>
int z[150]; 
int main()
{
	int s,n,count=0;


	while(scanf("%d",&s)!=EOF)
	{
		if(count-1<0&&s==0||count+1>100&&s==1)
		{
			
			printf("error ");
			continue;;
		}
		if(s==0)//pop
		{			count--;
			printf("%d ",z[count]);
			z[count]=0;

		}
		else if(s==1)//push
		{
		scanf("%d",&n);
		z[count]=n;
		count++;
		}
		else if(s==-1)
		{
			break;
		}

	} 
 
 
 
 	return 0;
}



