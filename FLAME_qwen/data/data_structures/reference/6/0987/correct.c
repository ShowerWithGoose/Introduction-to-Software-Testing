#include<stdio.h>

int Stack[100];


int main()
{
	int n=0;
	int top=0;
	int i=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&top);
			if(i<100)
			{
				Stack[i++]=top;
			}else{
				printf("error ");
			}
		}
		else if(n==0){
			if(i>0)
			{
				printf("%d ",Stack[i-1]);
				Stack[i-1]=0;
				i--;
			}
			else{
				printf("error ");
			}
		}else{
			break;
		}
	}
	
	return 0;
}

