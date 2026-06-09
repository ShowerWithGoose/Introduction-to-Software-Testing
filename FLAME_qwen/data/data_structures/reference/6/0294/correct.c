#include <stdio.h>

int main()
{
	int stack[100]={0},con,cnt=0,ele;
	while(scanf("%d",&con)!=EOF)
	{
		if(con==1)
		{
			scanf("%d",&ele);
			if(cnt>99)
			{
				printf("error ");
			}
			else
			{
				stack[cnt]=ele;
				cnt++;
			}
		}
		else if(con==0)
		{
			if(cnt<1)
			{
				printf("error "); 
			}
			else
			{
				cnt--;
				printf("%d ",stack[cnt]);
			}
		}
		else if(con==-1)
		{
			break;
		}
	}
	return 0;
}

